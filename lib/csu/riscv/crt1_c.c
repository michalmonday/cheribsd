/* LINTLIBRARY */
/*-
 * Copyright 1996-1998 John D. Polstra.
 * Copyright (c) 2015-2017 Ruslan Bukin <br@bsdpad.com>
 * All rights reserved.
 *
 * Portions of this software were developed by SRI International and the
 * University of Cambridge Computer Laboratory under DARPA/AFRL contract
 * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * Portions of this software were developed by the University of Cambridge
 * Computer Laboratory as part of the CTSRD Project, with support from the
 * UK Higher Education Innovation Fund (HEIF).
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <stdlib.h>

#include "libc_private.h"
#include "ignore_init.c"

#ifdef GCRT
extern void _mcleanup(void);
extern void monstartup(void *, void *);
extern int eprol;
extern int etext;
#endif

/*
 * For -pie executables rtld will process capability relocations, so we don't
 * need to include the code here.
 */
#if __has_feature(capabilities) && !defined(PIC)
#define SHOULD_PROCESS_CAP_RELOCS
#endif

#ifdef SHOULD_PROCESS_CAP_RELOCS
#include "crt_init_globals.c"
#endif

void __start(int argc, char **argv, char **env, void (*cleanup)(void));

void
__start(int argc, char **argv, char **env, void (*cleanup)(void))
{

#ifdef SHOULD_PROCESS_CAP_RELOCS
	/*
	 * Initialize __cap_relocs for static executables. The run-time linker
	 * will initialise any for dynamic executables.
	 */
	if (&_DYNAMIC == NULL) {
		const Elf_Auxinfo *auxp;
		char **strp;
		void *phdr = NULL;
		long phnum = 0;

		strp = env;
		while (*strp++ != NULL)
			;
		auxp = (Elf_Auxinfo *)strp;

		for (; auxp->a_type != AT_NULL; auxp++) {
			if (auxp->a_type == AT_PHDR) {
				phdr = auxp->a_un.a_ptr;
			} else if (auxp->a_type == AT_PHNUM) {
				phnum = auxp->a_un.a_val;
			}
		}

		if (phdr != NULL && phnum != 0) {
			crt_init_globals(phdr, phnum, NULL, NULL, NULL);
		}
	}
#endif

	handle_argv(argc, argv, env);

	if (&_DYNAMIC != NULL)
		atexit(cleanup);
	else
		_init_tls();

#ifdef GCRT
	atexit(_mcleanup);
	monstartup(&eprol, &etext);
__asm__("eprol:");
#endif

	handle_static_init(argc, argv, env);
	exit(main(argc, argv, env));
}
