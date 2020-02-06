/*-
 * Copyright (c) 2012-2018 Robert N. M. Watson
 * Copyright (c) 2014 SRI International
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Exercise CHERI functions without an expectation of a signal.
 */

#include <sys/cdefs.h>

#if !__has_feature(capabilities)
#error "This code requires a CHERI-aware compiler"
#endif

#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/time.h>

#include <machine/pte.h>
#include <machine/vmparam.h>

#include <cheri/cheri.h>
#include <cheri/cheric.h>

#include <err.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#include "cheribsdtest.h"

#ifdef __mips__
CHERIBSDTEST(test_copyregs, "Exercise CP2 register assignments")
{

	__asm__ __volatile__(
	    ".set push\n"
	    ".set noreorder\n"
	    "cgetdefault $c2\n"
	    "cmove $c3, $c2\n"
	    "cmove $c4, $c2\n"
	    "cmove $c5, $c2\n"
	    "cmove $c6, $c2\n"
	    "cmove $c7, $c2\n"
	    ".set pop\n"
	    : : : "$c2", "$c3", "$c4", "$c5", "$c6", "$c7");
	cheribsdtest_success();
}

CHERIBSDTEST(test_listregs, "Print out a list of CP2 registers and values",
    .ct_flags = CT_FLAG_STDOUT_IGNORE)
{

	/*
	 * Because of the assembly generated by CP2_CR_GET(), can't use a loop
	 * -- register numbers must be available at compile-time.
	 */
	printf("CP2 registers:\n");
	CHERI_CAPREG_PRINT(0);
	CHERI_CAPREG_PRINT(1);
	CHERI_CAPREG_PRINT(2);
	CHERI_CAPREG_PRINT(3);
	CHERI_CAPREG_PRINT(4);
	CHERI_CAPREG_PRINT(5);
	CHERI_CAPREG_PRINT(6);
	CHERI_CAPREG_PRINT(7);
	CHERI_CAPREG_PRINT(8);
	CHERI_CAPREG_PRINT(9);
	CHERI_CAPREG_PRINT(10);
	CHERI_CAPREG_PRINT(11);
	CHERI_CAPREG_PRINT(12);
	CHERI_CAPREG_PRINT(13);
	CHERI_CAPREG_PRINT(14);
	CHERI_CAPREG_PRINT(15);
	CHERI_CAPREG_PRINT(16);
	CHERI_CAPREG_PRINT(17);
	CHERI_CAPREG_PRINT(18);
	CHERI_CAPREG_PRINT(19);
	CHERI_CAPREG_PRINT(20);
	CHERI_CAPREG_PRINT(21);
	CHERI_CAPREG_PRINT(22);
	CHERI_CAPREG_PRINT(23);
	CHERI_CAPREG_PRINT(24);
	CHERI_CAPREG_PRINT(25);
	CHERI_CAPREG_PRINT(26);
	CHERI_PCC_PRINT();
	cheribsdtest_success();
}
#endif	/* __mips__ */

/*
 * These tests assume that the compiler and run-time libraries won't muck with
 * the global registers in question -- which is true at the time of writing.
 *
 * However, in the future, it could be that they are modified -- e.g., to
 * differentiate memory capabilities from class-type capabilities.  In that
 * case, these tests would need to check the original capability values saved
 * during process startup -- and also the new expected values.
 */
static void
check_initreg_code(void * __capability c)
{
	uintmax_t v;

	fprintf(stderr, "c %#lp\n", c);

#if defined(__CHERI_PURE_CAPABILITY__)
	/*
	 * Dynamically linked pure-capability code should have a program
	 * counter that is bounded to the current DSO/executable (or function).
	 */
	CHERIBSDTEST_VERIFY2(cheri_getbase(c) != 0, "code base should be nonzero");
	/*
	 * Check that PCC ends at the end of the current DSO (or executable in
	 * the statically linked case). Since we don't know the real value here,
	 * just check that it is less than PCC plus a constant that should be
	 * large enough for this binary (rounded to the next representable
	 * length).
	 */
	ptraddr_t upper_bound =
	    CHERI_REPRESENTABLE_LENGTH(cheri_getaddress(c) + 0x1000000);
	CHERIBSDTEST_VERIFY2(cheri_getlength(c) < upper_bound,
	    "code length 0x%jx should be < than 0x%jx)", cheri_getlength(c),
	    upper_bound);
#else
	/*
	 * In hybrid mode PCC should start at zero and extend to the end of the
	 * user address space.
	 */
	CHERIBSDTEST_VERIFY2(cheri_getbase(c) == CHERI_CAP_USER_CODE_BASE,
	    "code base 0x%jx (expected 0x%jx)", cheri_getbase(c),
	    (uintmax_t)CHERI_CAP_USER_CODE_BASE);
	CHERIBSDTEST_VERIFY2(cheri_getlength(c) == CHERI_CAP_USER_CODE_LENGTH,
	    "code length 0x%jx should be 0x%jx", cheri_getlength(c),
	    (uintmax_t)CHERI_CAP_USER_CODE_LENGTH);
#endif
	/* Offset. */
	CHERIBSDTEST_VERIFY(cheri_getoffset(c) == 0);

	/* Type -- should have unsealed type. */
	v = cheri_gettype(c);
	if (v != (uintmax_t)CHERI_OTYPE_UNSEALED)
		cheribsdtest_failure_errx("otype %jx (expected %jx)", v,
		    (uintmax_t)CHERI_OTYPE_UNSEALED);

	/* Sealed bit. */
	v = cheri_getsealed(c);
	if (v != 0)
		cheribsdtest_failure_errx("sealed %jx (expected 0)", v);

	/* Tag bit. */
	v = cheri_gettag(c);
	if (v != 1)
		cheribsdtest_failure_errx("tag %jx (expected 1)", v);

	/* Permissions. */
	v = cheri_getperm(c);
	/*
	 * More overt tests for permissions that should -- or should not -- be
	 * there, regardless of consistency with the kernel headers.
	 */
	if ((v & CHERI_PERM_GLOBAL) == 0)
		cheribsdtest_failure_errx("perms %jx (global missing)", v);

	if ((v & CHERI_PERM_EXECUTE) == 0)
		cheribsdtest_failure_errx("perms %jx (execute missing)", v);

	if ((v & CHERI_PERM_LOAD) == 0)
		cheribsdtest_failure_errx("perms %jx (load missing)", v);

	if ((v & CHERI_PERM_STORE) != 0)
		cheribsdtest_failure_errx("perms %jx (store present)", v);

	if ((v & CHERI_PERM_LOAD_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (loadcap missing)", v);

	if ((v & CHERI_PERM_STORE_CAP) != 0)
		cheribsdtest_failure_errx("perms %jx (storecap present)", v);

	if ((v & CHERI_PERM_STORE_LOCAL_CAP) != 0)
		cheribsdtest_failure_errx("perms %jx (store_local_cap present)",
		    v);

	if ((v & CHERI_PERM_SEAL) != 0)
		cheribsdtest_failure_errx("perms %jx (seal present)", v);

	if ((v & CHERI_PERM_CCALL) == 0)
		cheribsdtest_failure_errx("perms %jx (ccall missing)", v);

	if ((v & CHERI_PERM_UNSEAL) != 0)
		cheribsdtest_failure_errx("perms %jx (unseal present)", v);

	if ((v & CHERI_PERM_SYSTEM_REGS) != 0)
		cheribsdtest_failure_errx("perms %jx (system_regs present)", v);

	if ((v & CHERI_PERMS_SWALL) !=
	    (CHERI_PERMS_SWALL & ~CHERI_PERM_CHERIABI_VMMAP))
		cheribsdtest_failure_errx("swperms %jx (expected swperms %x)",
		    v & CHERI_PERMS_SWALL,
		    (CHERI_PERMS_SWALL & ~CHERI_PERM_CHERIABI_VMMAP));

	/* Check that the raw permission bits match the kernel header: */
	if (v != CHERI_CAP_USER_CODE_PERMS)
		cheribsdtest_failure_errx("perms %jx (expected %jx)", v,
		    (uintmax_t)CHERI_CAP_USER_CODE_PERMS);

	cheribsdtest_success();
}

#ifndef __CHERI_PURE_CAPABILITY__
static void
check_initreg_data_full_addrspace(void * __capability c)
{
	uintmax_t v;

	/* Base. */
	v = cheri_getbase(c);
	if (v != CHERI_CAP_USER_DATA_BASE)
		cheribsdtest_failure_errx("base %jx (expected %jx)", v,
		    (uintmax_t)CHERI_CAP_USER_DATA_BASE);

	/* Length. */
	v = cheri_getlen(c);
	if (v > CHERI_CAP_USER_DATA_LENGTH)
		cheribsdtest_failure_errx("length 0x%jx (expected <= 0x%jx)", v,
		    CHERI_CAP_USER_DATA_LENGTH);

	/* Offset. */
	v = cheri_getoffset(c);
	if (v != CHERI_CAP_USER_DATA_OFFSET)
		cheribsdtest_failure_errx("offset %jx (expected %jx)", v,
		    (uintmax_t)CHERI_CAP_USER_DATA_OFFSET);

	/* Type -- should have unsealed type. */
	v = cheri_gettype(c);
	if (v != (uintmax_t)CHERI_OTYPE_UNSEALED)
		cheribsdtest_failure_errx("otype %jx (expected %jx)", v,
		    (uintmax_t)CHERI_OTYPE_UNSEALED);

	/* Permissions. */
	v = cheri_getperm(c);
	if (v != (CHERI_CAP_USER_DATA_PERMS | CHERI_PERM_CHERIABI_VMMAP))
		cheribsdtest_failure_errx("perms %jx (expected %jx)", v,
		    (uintmax_t)CHERI_CAP_USER_DATA_PERMS |
		    CHERI_PERM_CHERIABI_VMMAP);

	/*
	 * More overt tests for permissions that should -- or should not -- be
	 * there, regardless of consistency with the kernel headers.
	 */
	if ((v & CHERI_PERM_GLOBAL) == 0)
		cheribsdtest_failure_errx("perms %jx (global missing)", v);

	if ((v & CHERI_PERM_EXECUTE) != 0)
		cheribsdtest_failure_errx("perms %jx (execute present)", v);

	if ((v & CHERI_PERM_LOAD) == 0)
		cheribsdtest_failure_errx("perms %jx (load missing)", v);

	if ((v & CHERI_PERM_STORE) == 0)
		cheribsdtest_failure_errx("perms %jx (store missing)", v);

	if ((v & CHERI_PERM_LOAD_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (loadcap missing)", v);

	if ((v & CHERI_PERM_STORE_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (storecap missing)", v);

	if ((v & CHERI_PERM_STORE_LOCAL_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (store_local_cap missing)",
		    v);

	if ((v & CHERI_PERM_SEAL) != 0)
		cheribsdtest_failure_errx("perms %jx (seal present)", v);

	if ((v & CHERI_PERM_CCALL) == 0)
		cheribsdtest_failure_errx("perms %jx (ccall missing)", v);

	if ((v & CHERI_PERM_UNSEAL) != 0)
		cheribsdtest_failure_errx("perms %jx (unseal present)", v);

	if ((v & CHERI_PERM_SYSTEM_REGS) != 0)
		cheribsdtest_failure_errx("perms %jx (system_regs present)", v);

	if ((v & CHERI_PERMS_SWALL) != CHERI_PERMS_SWALL)
		cheribsdtest_failure_errx("swperms %jx (expected swperms %x)",
		    v & CHERI_PERMS_SWALL, CHERI_PERMS_SWALL);

	/* Sealed bit. */
	v = cheri_getsealed(c);
	if (v != 0)
		cheribsdtest_failure_errx("sealed %jx (expected 0)", v);

	/* Tag bit. */
	v = cheri_gettag(c);
	if (v != 1)
		cheribsdtest_failure_errx("tag %jx (expected 1)", v);
	cheribsdtest_success();
}
#endif

CHERIBSDTEST(test_initregs_default, "Test initial value of default capability")
{

#ifdef __CHERI_PURE_CAPABILITY__
	if (cheri_getdefault() == NULL)
		cheribsdtest_success();
	else
		cheribsdtest_failure_errx("Expected NULL $ddc but was %-#p",
		    cheri_getdefault());

#else
	check_initreg_data_full_addrspace(cheri_getdefault());
#endif
}

/*
 * Outside of CheriABI, the stack pointer ($sp) is evaluated relative to the
 * default data capability, so no separate stack capability is defined.
 *
 * Inside CheriABI, the stack capability should contain only the specific
 * address range used for the stack.  We could try to capture the same logic
 * here as used in the kernel to select the stack -- but it seems more
 * sensible to simply assert that the capability is not the same as the
 * default capability for the MIPS ABI.
 */
#ifdef __CHERI_PURE_CAPABILITY__

/*
 * We require our stack offset to be somewhere in the first 256KiB.  That
 * should be plenty of room for the aux vector and args and all that.
 */

#define	CHERI_STACK_USE_MAX	(256 * 1024)

CHERIBSDTEST(test_initregs_stack_user_perms,
    "Test user permissions of stack capability")
{
	register_t v;

	v = cheri_getperm(cheri_getstack());
	if ((v & CHERI_PERMS_SWALL) !=
	    (CHERI_PERMS_SWALL & ~CHERI_PERM_CHERIABI_VMMAP))
		cheribsdtest_failure_errx("swperms %jx (expected swperms %x)",
		    v & CHERI_PERMS_SWALL,
		    (CHERI_PERMS_SWALL & ~CHERI_PERM_CHERIABI_VMMAP));
	cheribsdtest_success();
}

CHERIBSDTEST(test_initregs_stack,
    "Test initial value of stack capability")
{
	void * __capability c = cheri_getstack();
	register_t v;

	/* Base. */
	if (cheri_getbase(c) == CHERI_CAP_USER_DATA_BASE)
		cheribsdtest_failure_errx("base 0x%jx (did not expect 0x%jx)",
		    cheri_getbase(c), (uintmax_t)CHERI_CAP_USER_DATA_BASE);

	/* Length. */
	/* Technically dynamic, but defaults to MAXSSIZ. */
	if (cheri_getlen(c) > MAXSSIZ)
		cheribsdtest_failure_errx("length 0x%jx (> MAXSSIZ 0x%jx)",
		    cheri_getlen(c), (uintmax_t)MAXSSIZ);

	/* Offset. */
	/* If we're running len > offset... */
	if (cheri_getlen(c) - cheri_getoffset(c) > CHERI_STACK_USE_MAX)
		cheribsdtest_failure_errx("offset more then 0x%jx from top "
		    "(0x%jx)", (intmax_t)CHERI_STACK_USE_MAX,
		    cheri_getlen(c) - cheri_getoffset(c));

	/* Type -- should have unsealed type. */
	if (cheri_gettype(c) != CHERI_OTYPE_UNSEALED)
		cheribsdtest_failure_errx("otype 0x%jx (expected 0x%jx)",
		    cheri_gettype(c), (uintmax_t)CHERI_OTYPE_UNSEALED);

	/* Permissions. */
	v = cheri_getperm(c);

	/*
	 * More overt tests for permissions that should -- or should not -- be
	 * there, regardless of consistency with the kernel headers.
	 */
	if ((v & CHERI_PERM_EXECUTE) != 0)
		cheribsdtest_failure_errx("perms %jx (execute present)", v);

	if ((v & CHERI_PERM_LOAD) == 0)
		cheribsdtest_failure_errx("perms %jx (load missing)", v);

	if ((v & CHERI_PERM_LOAD_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (loadcap missing)", v);

	if ((v & CHERI_PERM_GLOBAL) == 0)
		cheribsdtest_failure_errx("perms %jx (global missing)", v);

	if ((v & CHERI_PERM_STORE) == 0)
		cheribsdtest_failure_errx("perms %jx (store missing)", v);

	if ((v & CHERI_PERM_STORE_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (storecap missing)", v);

	if ((v & CHERI_PERM_STORE_LOCAL_CAP) == 0)
		cheribsdtest_failure_errx("perms %jx (store_local_cap missing)",
		    v);

	if ((v & CHERI_PERM_SEAL) != 0)
		cheribsdtest_failure_errx("perms %jx (seal present)", v);

	if ((v & CHERI_PERM_SYSTEM_REGS) != 0)
		cheribsdtest_failure_errx("perms %jx (system_regs present)", v);

	if ((v & CHERI_PERM_CCALL) == 0)
		cheribsdtest_failure_errx("perms %jx (ccall missing)", v);

	if ((v & CHERI_PERM_UNSEAL) != 0)
		cheribsdtest_failure_errx("perms %jx (unseal present)", v);

	if (v != CHERI_CAP_USER_DATA_PERMS)
		cheribsdtest_failure_errx("perms %jx (expected %jx)", v,
		    (uintmax_t)(CHERI_CAP_USER_DATA_PERMS));

	/* Sealed bit. */
	v = cheri_getsealed(c);
	if (v != 0)
		cheribsdtest_failure_errx("sealed %jx (expected 0)", v);

	/* Tag bit. */
	v = cheri_gettag(c);
	if (v != 1)
		cheribsdtest_failure_errx("tag %jx (expected 1)", v);
	cheribsdtest_success();
}

CHERIBSDTEST(test_initregs_returncap, "Test value of return capability")
{
	void *c;
	uintmax_t v;
	
	/* The return capability should always be a sentry capability */
	c = __builtin_return_address(0);
	v = cheri_getperm(c);

	CHERIBSDTEST_VERIFY(cheri_gettag(c));
	/* Check that execute is present and store permissions aren't */
	CHERIBSDTEST_VERIFY2((v & CHERI_PERM_EXECUTE) == CHERI_PERM_EXECUTE,
	    "perms %jx (execute missing)", v);
	CHERIBSDTEST_VERIFY2((v & CHERI_PERM_STORE) == 0,
	    "perms %jx (store present)", v);
	CHERIBSDTEST_VERIFY2((v & CHERI_PERM_STORE_CAP) == 0,
	    "perms %jx (storecap present)", v);
	CHERIBSDTEST_VERIFY2((v & CHERI_PERM_STORE_LOCAL_CAP) == 0,
	    "perms %jx (store_local_cap present)", v);

	v = cheri_gettype(c);
	CHERIBSDTEST_VERIFY2(v == (uintmax_t)CHERI_OTYPE_SENTRY,
	    "otype %jx (expected %jx)", v, (uintmax_t)CHERI_OTYPE_SENTRY);

	/* __builtin_extract_return_addr() should be a no-op */
	CHERIBSDTEST_CHECK_EQ_CAP(c, __builtin_extract_return_addr(c));

	cheribsdtest_success();
}
#endif

#ifdef __mips__
CHERIBSDTEST(test_initregs_idc,
    "Test initial value of invoked data capability")
{

#ifndef __CHERI_PURE_CAPABILITY__
	CHERIBSDTEST_CHECK_EQ_CAP(cheri_getidc(), NULL);
#else
	void* __capability cgp = __builtin_mips_cheri_get_captable();
	uintmax_t perms = cheri_getperm(cgp);
	extern void _CHERI_CAPABILITY_TABLE_;
	void* __capability cap_table = &_CHERI_CAPABILITY_TABLE_;
	/* TODO: this should probably be a preprocessor macro instead */
	_Bool pcrelative_captable = (perms & CHERI_PERM_EXECUTE) != 0;

	CHERIBSDTEST_VERIFY(cheri_getlen(cgp) != 0);
	CHERIBSDTEST_VERIFY2((perms & CHERI_PERM_STORE) == 0,
	    "perms %jx (store should not be set)", perms);
	CHERIBSDTEST_VERIFY2((perms & CHERI_PERM_STORE_CAP) == 0,
	    "perms %jx (store_cap should not be set)", perms);
	CHERIBSDTEST_VERIFY2((perms & CHERI_PERM_STORE_LOCAL_CAP) == 0,
	    "perms %jx (store_local_cap should not be set)", perms);
	CHERIBSDTEST_VERIFY2((ptraddr_t)cap_table == (ptraddr_t)cgp,
	    "$cgp (%#p) does not point to _CHERI_CAPABILITY_TABLE_ (%#p)", cgp,
	    cap_table);

	/* XXXAR: pcrelative ABI is a bit different: */
	if (pcrelative_captable) {
		CHERIBSDTEST_VERIFY(cheri_getoffset(cgp) != 0);
		void* __capability pcc = cheri_getpcc();
		CHERIBSDTEST_VERIFY(cheri_getbase(cgp) == cheri_getbase(pcc));
	} else {
		CHERIBSDTEST_VERIFY(cheri_getbase(cgp) != 0);
		CHERIBSDTEST_VERIFY(cheri_getbase(cgp) == cheri_getbase(cap_table));
		CHERIBSDTEST_VERIFY(cheri_getlen(cgp) == cheri_getlen(cap_table));
		CHERIBSDTEST_VERIFY(cheri_getoffset(cgp) == cheri_getoffset(cap_table));
		CHERIBSDTEST_VERIFY2((perms & CHERI_PERM_EXECUTE) == 0,
			"perms %jx (execute should not be set)", perms);
	}
#endif
	cheribsdtest_success();
}
#endif

CHERIBSDTEST(test_initregs_pcc,
    "Test initial value of program-counter capability")
{
	void * __capability c;

	/* $pcc includes $pc, so clear that for the purposes of the check. */
	c = cheri_getpcc();
	c = cheri_setoffset(c, 0);
	check_initreg_code(c);
}

#ifdef __aarch64__
CHERIBSDTEST(test_initregs_restricted_default,
    "Test initial value of restricted default capability");
{
	void * __capability c;

	/* XXX: There don't seem to be intrisics; use once they exist */
	__asm__ ("mrs %0, rddc_el0" : "=C"(c));
	CHERIBSDTEST_CHECK_EQ_CAP(c, NULL);

	cheribsdtest_success();
}

CHERIBSDTEST(test_initregs_restricted_stack,
    "Test initial value of restricted stack capability");
{
	void * __capability c;

	/* XXX: There don't seem to be intrisics; use once they exist */
	__asm__ ("mrs %0, rcsp_el0" : "=C"(c));
	CHERIBSDTEST_CHECK_EQ_CAP(c, NULL);

	cheribsdtest_success();
}

CHERIBSDTEST(test_initregs_restricted_thread,
    "Test initial value of restricted thread capability");
{
	void * __capability c;

	/* XXX: There don't seem to be intrisics; use once they exist */
	__asm__ ("mrs %0, rctpidr_el0" : "=C"(c));
	CHERIBSDTEST_CHECK_EQ_CAP(c, NULL);

	cheribsdtest_success();
}
#endif
