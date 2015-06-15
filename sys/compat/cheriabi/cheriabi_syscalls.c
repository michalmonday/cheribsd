/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 * created from FreeBSD
 */

const char *cheriabi_syscallnames[] = {
#if !defined(PAD64_REQUIRED) && (defined(__powerpc__) || defined(__mips__))
#define PAD64_REQUIRED
#endif
	"syscall",			/* 0 = syscall */
	"exit",			/* 1 = exit */
	"fork",			/* 2 = fork */
	"read",			/* 3 = read */
	"write",			/* 4 = write */
	"open",			/* 5 = open */
	"close",			/* 6 = close */
	"wait4",			/* 7 = wait4 */
	"obs_old",			/* 8 = obsolete old creat */
	"link",			/* 9 = link */
	"unlink",			/* 10 = unlink */
	"obs_execv",			/* 11 = obsolete execv */
	"chdir",			/* 12 = chdir */
	"fchdir",			/* 13 = fchdir */
	"mknod",			/* 14 = mknod */
	"chmod",			/* 15 = chmod */
	"chown",			/* 16 = chown */
	"break",			/* 17 = break */
	"obs_getstatfs",			/* 18 = obsolete getstatfs */
	"obs_lseek",			/* 19 = obsolete lseek */
	"getpid",			/* 20 = getpid */
	"mount",			/* 21 = mount */
	"unmount",			/* 22 = unmount */
	"setuid",			/* 23 = setuid */
	"getuid",			/* 24 = getuid */
	"geteuid",			/* 25 = geteuid */
	"ptrace",			/* 26 = ptrace */
	"cheriabi_recvmsg",			/* 27 = cheriabi_recvmsg */
	"cheriabi_sendmsg",			/* 28 = cheriabi_sendmsg */
	"recvfrom",			/* 29 = recvfrom */
	"accept",			/* 30 = accept */
	"getpeername",			/* 31 = getpeername */
	"getsockname",			/* 32 = getsockname */
	"access",			/* 33 = access */
	"chflags",			/* 34 = chflags */
	"fchflags",			/* 35 = fchflags */
	"sync",			/* 36 = sync */
	"kill",			/* 37 = kill */
	"obs_stat",			/* 38 = obsolete stat */
	"getppid",			/* 39 = getppid */
	"obs_lstat",			/* 40 = obsolete lstat */
	"dup",			/* 41 = dup */
	"pipe",			/* 42 = pipe */
	"getegid",			/* 43 = getegid */
	"profil",			/* 44 = profil */
	"ktrace",			/* 45 = ktrace */
	"obs_sigaction",			/* 46 = obsolete sigaction */
	"getgid",			/* 47 = getgid */
	"obs_sigprocmask",			/* 48 = obsolete sigprocmask */
	"getlogin",			/* 49 = getlogin */
	"setlogin",			/* 50 = setlogin */
	"acct",			/* 51 = acct */
	"obs_sigpending",			/* 52 = obsolete sigpending */
	"sigaltstack",			/* 53 = sigaltstack */
	"cheriabi_ioctl",			/* 54 = cheriabi_ioctl */
	"reboot",			/* 55 = reboot */
	"revoke",			/* 56 = revoke */
	"symlink",			/* 57 = symlink */
	"readlink",			/* 58 = readlink */
	"cheriabi_execve",			/* 59 = cheriabi_execve */
	"umask",			/* 60 = umask */
	"chroot",			/* 61 = chroot */
	"obs_fstat",			/* 62 = obsolete fstat */
	"obs_ogetkerninfo",			/* 63 = obsolete ogetkerninfo */
	"obs_getpagesize",			/* 64 = obsolete getpagesize */
	"msync",			/* 65 = msync */
	"vfork",			/* 66 = vfork */
	"obs_vread",			/* 67 = obsolete vread */
	"obs_vwrite",			/* 68 = obsolete vwrite */
	"sbrk",			/* 69 = sbrk */
	"sstk",			/* 70 = sstk */
	"obs_mmap",			/* 71 = obsolete mmap */
	"vadvise",			/* 72 = vadvise */
	"munmap",			/* 73 = munmap */
	"mprotect",			/* 74 = mprotect */
	"madvise",			/* 75 = madvise */
	"obs_vhangup",			/* 76 = obsolete vhangup */
	"obs_vlimit",			/* 77 = obsolete vlimit */
	"mincore",			/* 78 = mincore */
	"getgroups",			/* 79 = getgroups */
	"setgroups",			/* 80 = setgroups */
	"getpgrp",			/* 81 = getpgrp */
	"setpgid",			/* 82 = setpgid */
	"setitimer",			/* 83 = setitimer */
	"obs_owait",			/* 84 = obsolete owait */
	"swapon",			/* 85 = swapon */
	"getitimer",			/* 86 = getitimer */
	"obs_ogethostname",			/* 87 = obsolete ogethostname */
	"obs_osethostname",			/* 88 = obsolete osethostname */
	"getdtablesize",			/* 89 = getdtablesize */
	"dup2",			/* 90 = dup2 */
	"#91",			/* 91 = getdopt */
	"fcntl",			/* 92 = fcntl */
	"select",			/* 93 = select */
	"#94",			/* 94 = setdopt */
	"fsync",			/* 95 = fsync */
	"setpriority",			/* 96 = setpriority */
	"socket",			/* 97 = socket */
	"connect",			/* 98 = connect */
	"obs_oaccept",			/* 99 = obsolete oaccept */
	"getpriority",			/* 100 = getpriority */
	"obs_osend",			/* 101 = obsolete osend */
	"obs_orecv",			/* 102 = obsolete orecv */
	"obs_sigreturn",			/* 103 = obsolete sigreturn */
	"bind",			/* 104 = bind */
	"setsockopt",			/* 105 = setsockopt */
	"listen",			/* 106 = listen */
	"obs_vtimes",			/* 107 = obsolete vtimes */
	"obs_sigvec",			/* 108 = obsolete sigvec */
	"obs_sigblock",			/* 109 = obsolete sigblock */
	"obs_sigsetmask",			/* 110 = obsolete sigsetmask */
	"obs_sigsuspend",			/* 111 = obsolete sigsuspend */
	"obs_sigstack",			/* 112 = obsolete sigstack */
	"obs_orecvmsg",			/* 113 = obsolete orecvmsg */
	"obs_osendmsg",			/* 114 = obsolete osendmsg */
	"obs_vtrace",			/* 115 = obsolete vtrace */
	"gettimeofday",			/* 116 = gettimeofday */
	"getrusage",			/* 117 = getrusage */
	"getsockopt",			/* 118 = getsockopt */
	"#119",			/* 119 = resuba */
	"cheriabi_readv",			/* 120 = cheriabi_readv */
	"cheriabi_writev",			/* 121 = cheriabi_writev */
	"settimeofday",			/* 122 = settimeofday */
	"fchown",			/* 123 = fchown */
	"fchmod",			/* 124 = fchmod */
	"obs_orecvfrom",			/* 125 = obsolete orecvfrom */
	"setreuid",			/* 126 = setreuid */
	"setregid",			/* 127 = setregid */
	"rename",			/* 128 = rename */
	"obs_truncate",			/* 129 = obsolete truncate */
	"obs_ftruncate",			/* 130 = obsolete ftruncate */
	"flock",			/* 131 = flock */
	"mkfifo",			/* 132 = mkfifo */
	"sendto",			/* 133 = sendto */
	"shutdown",			/* 134 = shutdown */
	"socketpair",			/* 135 = socketpair */
	"mkdir",			/* 136 = mkdir */
	"rmdir",			/* 137 = rmdir */
	"utimes",			/* 138 = utimes */
	"obs_sigreturn",			/* 139 = obsolete sigreturn */
	"adjtime",			/* 140 = adjtime */
	"obs_ogetpeername",			/* 141 = obsolete ogetpeername */
	"obs_ogethostid",			/* 142 = obsolete ogethostid */
	"obs_sethostid",			/* 143 = obsolete sethostid */
	"obs_getrlimit",			/* 144 = obsolete getrlimit */
	"obs_setrlimit",			/* 145 = obsolete setrlimit */
	"obs_killpg",			/* 146 = obsolete killpg */
	"setsid",			/* 147 = setsid */
	"quotactl",			/* 148 = quotactl */
	"obs_oquota",			/* 149 = obsolete oquota */
	"obs_ogetsockname",			/* 150 = obsolete ogetsockname */
	"#151",			/* 151 = sem_lock */
	"#152",			/* 152 = sem_wakeup */
	"#153",			/* 153 = asyncdaemon */
	"#154",			/* 154 = nlm_syscall */
	"#155",			/* 155 = nfssvc */
	"obs_getdirentries",			/* 156 = obsolete getdirentries */
	"obs_statfs",			/* 157 = obsolete statfs */
	"obs_fstatfs",			/* 158 = obsolete fstatfs */
	"#159",			/* 159 = nosys */
	"#160",			/* 160 = lgetfh */
	"getfh",			/* 161 = getfh */
	"obs_getdomainname",			/* 162 = obsolete getdomainname */
	"obs_setdomainname",			/* 163 = obsolete setdomainname */
	"obs_uname",			/* 164 = obsolete uname */
	"sysarch",			/* 165 = sysarch */
	"rtprio",			/* 166 = rtprio */
	"#167",			/* 167 = nosys */
	"#168",			/* 168 = nosys */
	"semsys",			/* 169 = semsys */
	"msgsys",			/* 170 = msgsys */
	"shmsys",			/* 171 = shmsys */
	"#172",			/* 172 = nosys */
	"obs_pread",			/* 173 = obsolete pread */
	"obs_pwrite",			/* 174 = obsolete pwrite */
	"#175",			/* 175 = nosys */
	"ntp_adjtime",			/* 176 = ntp_adjtime */
	"#177",			/* 177 = sfork */
	"#178",			/* 178 = getdescriptor */
	"#179",			/* 179 = setdescriptor */
	"#180",			/* 180 = nosys */
	"setgid",			/* 181 = setgid */
	"setegid",			/* 182 = setegid */
	"seteuid",			/* 183 = seteuid */
	"#184",			/* 184 = lfs_bmapv */
	"#185",			/* 185 = lfs_markv */
	"#186",			/* 186 = lfs_segclean */
	"#187",			/* 187 = lfs_segwait */
	"stat",			/* 188 = stat */
	"fstat",			/* 189 = fstat */
	"lstat",			/* 190 = lstat */
	"pathconf",			/* 191 = pathconf */
	"fpathconf",			/* 192 = fpathconf */
	"#193",			/* 193 = nosys */
	"getrlimit",			/* 194 = getrlimit */
	"setrlimit",			/* 195 = setrlimit */
	"getdirentries",			/* 196 = getdirentries */
	"obs_mmap",			/* 197 = obsolete mmap */
	"__syscall",			/* 198 = __syscall */
	"obs_lseek",			/* 199 = obsolete lseek */
	"obs_truncate",			/* 200 = obsolete truncate */
	"obs_ftruncate",			/* 201 = obsolete ftruncate */
	"__sysctl",			/* 202 = __sysctl */
	"mlock",			/* 203 = mlock */
	"munlock",			/* 204 = munlock */
	"undelete",			/* 205 = undelete */
	"futimes",			/* 206 = futimes */
	"getpgid",			/* 207 = getpgid */
	"#208",			/* 208 = newreboot */
	"poll",			/* 209 = poll */
	"lkmnosys",			/* 210 = lkmnosys */
	"lkmnosys",			/* 211 = lkmnosys */
	"lkmnosys",			/* 212 = lkmnosys */
	"lkmnosys",			/* 213 = lkmnosys */
	"lkmnosys",			/* 214 = lkmnosys */
	"lkmnosys",			/* 215 = lkmnosys */
	"lkmnosys",			/* 216 = lkmnosys */
	"lkmnosys",			/* 217 = lkmnosys */
	"lkmnosys",			/* 218 = lkmnosys */
	"lkmnosys",			/* 219 = lkmnosys */
	"obs_semctl",			/* 220 = obsolete semctl */
	"semget",			/* 221 = semget */
	"semop",			/* 222 = semop */
	"#223",			/* 223 = semconfig */
	"obs_msgctl",			/* 224 = obsolete msgctl */
	"msgget",			/* 225 = msgget */
	"msgsnd",			/* 226 = msgsnd */
	"msgrcv",			/* 227 = msgrcv */
	"shmat",			/* 228 = shmat */
	"obs_shmctl",			/* 229 = obsolete shmctl */
	"shmdt",			/* 230 = shmdt */
	"shmget",			/* 231 = shmget */
	"clock_gettime",			/* 232 = clock_gettime */
	"clock_settime",			/* 233 = clock_settime */
	"clock_getres",			/* 234 = clock_getres */
	"cheriabi_ktimer_create",			/* 235 = cheriabi_ktimer_create */
	"ktimer_delete",			/* 236 = ktimer_delete */
	"ktimer_settime",			/* 237 = ktimer_settime */
	"ktimer_gettime",			/* 238 = ktimer_gettime */
	"ktimer_getoverrun",			/* 239 = ktimer_getoverrun */
	"nanosleep",			/* 240 = nanosleep */
	"ffclock_getcounter",			/* 241 = ffclock_getcounter */
	"ffclock_setestimate",			/* 242 = ffclock_setestimate */
	"ffclock_getestimate",			/* 243 = ffclock_getestimate */
	"#244",			/* 244 = nosys */
	"#245",			/* 245 = nosys */
	"#246",			/* 246 = nosys */
	"clock_getcpuclockid2",			/* 247 = clock_getcpuclockid2 */
	"#248",			/* 248 = ntp_gettime */
	"#249",			/* 249 = nosys */
	"minherit",			/* 250 = minherit */
	"rfork",			/* 251 = rfork */
	"openbsd_poll",			/* 252 = openbsd_poll */
	"issetugid",			/* 253 = issetugid */
	"lchown",			/* 254 = lchown */
	"cheriabi_aio_read",			/* 255 = cheriabi_aio_read */
	"cheriabi_aio_write",			/* 256 = cheriabi_aio_write */
	"cheriabi_lio_listio",			/* 257 = cheriabi_lio_listio */
	"#258",			/* 258 = nosys */
	"#259",			/* 259 = nosys */
	"#260",			/* 260 = nosys */
	"#261",			/* 261 = nosys */
	"#262",			/* 262 = nosys */
	"#263",			/* 263 = nosys */
	"#264",			/* 264 = nosys */
	"#265",			/* 265 = nosys */
	"#266",			/* 266 = nosys */
	"#267",			/* 267 = nosys */
	"#268",			/* 268 = nosys */
	"#269",			/* 269 = nosys */
	"#270",			/* 270 = nosys */
	"#271",			/* 271 = nosys */
	"getdents",			/* 272 = getdents */
	"#273",			/* 273 = nosys */
	"lchmod",			/* 274 = lchmod */
	"netbsd_lchown",			/* 275 = netbsd_lchown */
	"lutimes",			/* 276 = lutimes */
	"netbsd_msync",			/* 277 = netbsd_msync */
	"nstat",			/* 278 = nstat */
	"nfstat",			/* 279 = nfstat */
	"nlstat",			/* 280 = nlstat */
	"#281",			/* 281 = nosys */
	"#282",			/* 282 = nosys */
	"#283",			/* 283 = nosys */
	"#284",			/* 284 = nosys */
	"#285",			/* 285 = nosys */
	"#286",			/* 286 = nosys */
	"#287",			/* 287 = nosys */
	"#288",			/* 288 = nosys */
	"cheriabi_preadv",			/* 289 = cheriabi_preadv */
	"cheriabi_pwritev",			/* 290 = cheriabi_pwritev */
	"#291",			/* 291 = nosys */
	"#292",			/* 292 = nosys */
	"#293",			/* 293 = nosys */
	"#294",			/* 294 = nosys */
	"#295",			/* 295 = nosys */
	"#296",			/* 296 = nosys */
	"obs_fhstatfs",			/* 297 = obsolete fhstatfs */
	"fhopen",			/* 298 = fhopen */
	"fhstat",			/* 299 = fhstat */
	"modnext",			/* 300 = modnext */
	"modstat",			/* 301 = modstat */
	"modfnext",			/* 302 = modfnext */
	"modfind",			/* 303 = modfind */
	"kldload",			/* 304 = kldload */
	"kldunload",			/* 305 = kldunload */
	"kldfind",			/* 306 = kldfind */
	"kldnext",			/* 307 = kldnext */
	"kldstat",			/* 308 = kldstat */
	"kldfirstmod",			/* 309 = kldfirstmod */
	"getsid",			/* 310 = getsid */
	"setresuid",			/* 311 = setresuid */
	"setresgid",			/* 312 = setresgid */
	"obs_signanosleep",			/* 313 = obsolete signanosleep */
	"cheriabi_aio_return",			/* 314 = cheriabi_aio_return */
	"cheriabi_aio_suspend",			/* 315 = cheriabi_aio_suspend */
	"cheriabi_aio_cancel",			/* 316 = cheriabi_aio_cancel */
	"cheriabi_aio_error",			/* 317 = cheriabi_aio_error */
	"obs_oaio_read",			/* 318 = obsolete oaio_read */
	"obs_oaio_write",			/* 319 = obsolete oaio_write */
	"obs_olio_listio",			/* 320 = obsolete olio_listio */
	"yield",			/* 321 = yield */
	"obs_thr_sleep",			/* 322 = obsolete thr_sleep */
	"obs_thr_wakeup",			/* 323 = obsolete thr_wakeup */
	"mlockall",			/* 324 = mlockall */
	"munlockall",			/* 325 = munlockall */
	"__getcwd",			/* 326 = __getcwd */
	"sched_setparam",			/* 327 = sched_setparam */
	"sched_getparam",			/* 328 = sched_getparam */
	"sched_setscheduler",			/* 329 = sched_setscheduler */
	"sched_getscheduler",			/* 330 = sched_getscheduler */
	"sched_yield",			/* 331 = sched_yield */
	"sched_get_priority_max",			/* 332 = sched_get_priority_max */
	"sched_get_priority_min",			/* 333 = sched_get_priority_min */
	"sched_rr_get_interval",			/* 334 = sched_rr_get_interval */
	"utrace",			/* 335 = utrace */
	"obs_sendfile",			/* 336 = obsolete sendfile */
	"kldsym",			/* 337 = kldsym */
	"cheriabi_jail",			/* 338 = cheriabi_jail */
	"#339",			/* 339 = pioctl */
	"sigprocmask",			/* 340 = sigprocmask */
	"sigsuspend",			/* 341 = sigsuspend */
	"obs_sigaction",			/* 342 = obsolete sigaction */
	"sigpending",			/* 343 = sigpending */
	"obs_sigreturn",			/* 344 = obsolete sigreturn */
	"cheriabi_sigtimedwait",			/* 345 = cheriabi_sigtimedwait */
	"cheriabi_sigwaitinfo",			/* 346 = cheriabi_sigwaitinfo */
	"__acl_get_file",			/* 347 = __acl_get_file */
	"__acl_set_file",			/* 348 = __acl_set_file */
	"__acl_get_fd",			/* 349 = __acl_get_fd */
	"__acl_set_fd",			/* 350 = __acl_set_fd */
	"__acl_delete_file",			/* 351 = __acl_delete_file */
	"__acl_delete_fd",			/* 352 = __acl_delete_fd */
	"__acl_aclcheck_file",			/* 353 = __acl_aclcheck_file */
	"__acl_aclcheck_fd",			/* 354 = __acl_aclcheck_fd */
	"extattrctl",			/* 355 = extattrctl */
	"extattr_set_file",			/* 356 = extattr_set_file */
	"extattr_get_file",			/* 357 = extattr_get_file */
	"extattr_delete_file",			/* 358 = extattr_delete_file */
	"cheriabi_aio_waitcomplete",			/* 359 = cheriabi_aio_waitcomplete */
	"getresuid",			/* 360 = getresuid */
	"getresgid",			/* 361 = getresgid */
	"kqueue",			/* 362 = kqueue */
	"cheriabi_kevent",			/* 363 = cheriabi_kevent */
	"#364",			/* 364 = __cap_get_proc */
	"#365",			/* 365 = __cap_set_proc */
	"#366",			/* 366 = __cap_get_fd */
	"#367",			/* 367 = __cap_get_file */
	"#368",			/* 368 = __cap_set_fd */
	"#369",			/* 369 = __cap_set_file */
	"#370",			/* 370 = nosys */
	"extattr_set_fd",			/* 371 = extattr_set_fd */
	"extattr_get_fd",			/* 372 = extattr_get_fd */
	"extattr_delete_fd",			/* 373 = extattr_delete_fd */
	"__setugid",			/* 374 = __setugid */
	"#375",			/* 375 = nfsclnt */
	"eaccess",			/* 376 = eaccess */
	"#377",			/* 377 = afs_syscall */
	"cheriabi_nmount",			/* 378 = cheriabi_nmount */
	"#379",			/* 379 = kse_exit */
	"#380",			/* 380 = kse_wakeup */
	"#381",			/* 381 = kse_create */
	"#382",			/* 382 = kse_thr_interrupt */
	"#383",			/* 383 = kse_release */
	"#384",			/* 384 = __mac_get_proc */
	"#385",			/* 385 = __mac_set_proc */
	"#386",			/* 386 = __mac_get_fd */
	"#387",			/* 387 = __mac_get_file */
	"#388",			/* 388 = __mac_set_fd */
	"#389",			/* 389 = __mac_set_file */
	"kenv",			/* 390 = kenv */
	"lchflags",			/* 391 = lchflags */
	"uuidgen",			/* 392 = uuidgen */
	"cheriabi_sendfile",			/* 393 = cheriabi_sendfile */
	"#394",			/* 394 = mac_syscall */
	"getfsstat",			/* 395 = getfsstat */
	"statfs",			/* 396 = statfs */
	"fstatfs",			/* 397 = fstatfs */
	"fhstatfs",			/* 398 = fhstatfs */
	"#399",			/* 399 = nosys */
	"ksem_close",			/* 400 = ksem_close */
	"ksem_post",			/* 401 = ksem_post */
	"ksem_wait",			/* 402 = ksem_wait */
	"ksem_trywait",			/* 403 = ksem_trywait */
	"ksem_init",			/* 404 = ksem_init */
	"ksem_open",			/* 405 = ksem_open */
	"ksem_unlink",			/* 406 = ksem_unlink */
	"ksem_getvalue",			/* 407 = ksem_getvalue */
	"ksem_destroy",			/* 408 = ksem_destroy */
	"#409",			/* 409 = __mac_get_pid */
	"#410",			/* 410 = __mac_get_link */
	"#411",			/* 411 = __mac_set_link */
	"extattr_set_link",			/* 412 = extattr_set_link */
	"extattr_get_link",			/* 413 = extattr_get_link */
	"extattr_delete_link",			/* 414 = extattr_delete_link */
	"#415",			/* 415 = __mac_execve */
	"sigaction",			/* 416 = sigaction */
	"sigreturn",			/* 417 = sigreturn */
	"#418",			/* 418 = __xstat */
	"#419",			/* 419 = __xfstat */
	"#420",			/* 420 = __xlstat */
	"getcontext",			/* 421 = getcontext */
	"setcontext",			/* 422 = setcontext */
	"swapcontext",			/* 423 = swapcontext */
	"#424",			/* 424 = swapoff */
	"__acl_get_link",			/* 425 = __acl_get_link */
	"__acl_set_link",			/* 426 = __acl_set_link */
	"__acl_delete_link",			/* 427 = __acl_delete_link */
	"__acl_aclcheck_link",			/* 428 = __acl_aclcheck_link */
	"sigwait",			/* 429 = sigwait */
	"#430",			/* 430 = thr_create; */
	"thr_exit",			/* 431 = thr_exit */
	"thr_self",			/* 432 = thr_self */
	"thr_kill",			/* 433 = thr_kill */
	"#434",			/* 434 = nosys */
	"#435",			/* 435 = nosys */
	"jail_attach",			/* 436 = jail_attach */
	"extattr_list_fd",			/* 437 = extattr_list_fd */
	"extattr_list_file",			/* 438 = extattr_list_file */
	"extattr_list_link",			/* 439 = extattr_list_link */
	"#440",			/* 440 = kse_switchin */
	"ksem_timedwait",			/* 441 = ksem_timedwait */
	"thr_suspend",			/* 442 = thr_suspend */
	"thr_wake",			/* 443 = thr_wake */
	"kldunloadf",			/* 444 = kldunloadf */
	"audit",			/* 445 = audit */
	"auditon",			/* 446 = auditon */
	"getauid",			/* 447 = getauid */
	"setauid",			/* 448 = setauid */
	"getaudit",			/* 449 = getaudit */
	"setaudit",			/* 450 = setaudit */
	"getaudit_addr",			/* 451 = getaudit_addr */
	"setaudit_addr",			/* 452 = setaudit_addr */
	"auditctl",			/* 453 = auditctl */
	"_umtx_op",			/* 454 = _umtx_op */
	"cheriabi_thr_new",			/* 455 = cheriabi_thr_new */
	"sigqueue",			/* 456 = sigqueue */
	"kmq_open",			/* 457 = kmq_open */
	"kmq_setattr",			/* 458 = kmq_setattr */
	"kmq_timedreceive",			/* 459 = kmq_timedreceive */
	"kmq_timedsend",			/* 460 = kmq_timedsend */
	"cheriabi_kmq_notify",			/* 461 = cheriabi_kmq_notify */
	"kmq_unlink",			/* 462 = kmq_unlink */
	"abort2",			/* 463 = abort2 */
	"thr_set_name",			/* 464 = thr_set_name */
	"cheriabi_aio_fsync",			/* 465 = cheriabi_aio_fsync */
	"rtprio_thread",			/* 466 = rtprio_thread */
	"#467",			/* 467 = nosys */
	"#468",			/* 468 = nosys */
	"#469",			/* 469 = __getpath_fromfd */
	"#470",			/* 470 = __getpath_fromaddr */
	"sctp_peeloff",			/* 471 = sctp_peeloff */
	"sctp_generic_sendmsg",			/* 472 = sctp_generic_sendmsg */
	"sctp_generic_sendmsg_iov",			/* 473 = sctp_generic_sendmsg_iov */
	"sctp_generic_recvmsg",			/* 474 = sctp_generic_recvmsg */
	"pread",			/* 475 = pread */
	"pwrite",			/* 476 = pwrite */
	"mmap",			/* 477 = mmap */
	"lseek",			/* 478 = lseek */
	"truncate",			/* 479 = truncate */
	"ftruncate",			/* 480 = ftruncate */
	"thr_kill2",			/* 481 = thr_kill2 */
	"shm_open",			/* 482 = shm_open */
	"shm_unlink",			/* 483 = shm_unlink */
	"cpuset",			/* 484 = cpuset */
	"cpuset_setid",			/* 485 = cpuset_setid */
	"cpuset_getid",			/* 486 = cpuset_getid */
	"cpuset_getaffinity",			/* 487 = cpuset_getaffinity */
	"cpuset_setaffinity",			/* 488 = cpuset_setaffinity */
	"faccessat",			/* 489 = faccessat */
	"fchmodat",			/* 490 = fchmodat */
	"fchownat",			/* 491 = fchownat */
	"cheriabi_fexecve",			/* 492 = cheriabi_fexecve */
	"fstatat",			/* 493 = fstatat */
	"futimesat",			/* 494 = futimesat */
	"linkat",			/* 495 = linkat */
	"mkdirat",			/* 496 = mkdirat */
	"mkfifoat",			/* 497 = mkfifoat */
	"mknodat",			/* 498 = mknodat */
	"openat",			/* 499 = openat */
	"readlinkat",			/* 500 = readlinkat */
	"renameat",			/* 501 = renameat */
	"symlinkat",			/* 502 = symlinkat */
	"unlinkat",			/* 503 = unlinkat */
	"posix_openpt",			/* 504 = posix_openpt */
	"#505",			/* 505 = gssd_syscall */
	"cheriabi_jail_get",			/* 506 = cheriabi_jail_get */
	"cheriabi_jail_set",			/* 507 = cheriabi_jail_set */
	"jail_remove",			/* 508 = jail_remove */
	"closefrom",			/* 509 = closefrom */
	"cheriabi_semctl",			/* 510 = cheriabi_semctl */
	"cheriabi_msgctl",			/* 511 = cheriabi_msgctl */
	"shmctl",			/* 512 = shmctl */
	"lpathconf",			/* 513 = lpathconf */
	"obs_cap_new",			/* 514 = obsolete cap_new */
	"__cap_rights_get",			/* 515 = __cap_rights_get */
	"cheriabi_cap_enter",			/* 516 = cheriabi_cap_enter */
	"cap_getmode",			/* 517 = cap_getmode */
	"pdfork",			/* 518 = pdfork */
	"pdkill",			/* 519 = pdkill */
	"pdgetpid",			/* 520 = pdgetpid */
	"#521",			/* 521 = pdwait4 */
	"pselect",			/* 522 = pselect */
	"getloginclass",			/* 523 = getloginclass */
	"setloginclass",			/* 524 = setloginclass */
	"rctl_get_racct",			/* 525 = rctl_get_racct */
	"rctl_get_rules",			/* 526 = rctl_get_rules */
	"rctl_get_limits",			/* 527 = rctl_get_limits */
	"rctl_add_rule",			/* 528 = rctl_add_rule */
	"rctl_remove_rule",			/* 529 = rctl_remove_rule */
	"posix_fallocate",			/* 530 = posix_fallocate */
	"posix_fadvise",			/* 531 = posix_fadvise */
	"cheriabi_wait6",			/* 532 = cheriabi_wait6 */
	"cap_rights_limit",			/* 533 = cap_rights_limit */
	"cheriabi_cap_ioctls_limit",			/* 534 = cheriabi_cap_ioctls_limit */
	"cheriabi_cap_ioctls_get",			/* 535 = cheriabi_cap_ioctls_get */
	"cap_fcntls_limit",			/* 536 = cap_fcntls_limit */
	"cap_fcntls_get",			/* 537 = cap_fcntls_get */
	"bindat",			/* 538 = bindat */
	"connectat",			/* 539 = connectat */
	"chflagsat",			/* 540 = chflagsat */
	"accept4",			/* 541 = accept4 */
	"pipe2",			/* 542 = pipe2 */
	"cheriabi_aio_mlock",			/* 543 = cheriabi_aio_mlock */
	"procctl",			/* 544 = procctl */
	"ppoll",			/* 545 = ppoll */
	"futimens",			/* 546 = futimens */
	"utimensat",			/* 547 = utimensat */
};
