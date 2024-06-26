SHLIBDIR?=	/lib

.include <src.opts.mk>

PACKAGE=	clibs
_LIBCXXRTDIR=   ${SRCTOP}/contrib/subrepo-cheri-libcxxrt/src
HDRDIR=         ${SRCTOP}/contrib/subrepo-cheri-libc++/include
SRCDIR=         ${SRCTOP}/contrib/subrepo-cheri-libc++/src
CXXINCLUDEDIR=	${INCLUDEDIR}/c++/v${SHLIB_MAJOR}

.PATH: ${SRCDIR}

LIB=		c++
SHLIB_MAJOR=	1
SHLIB_LDSCRIPT=	libc++.ldscript

SRCS+=		algorithm.cpp
SRCS+=		any.cpp
SRCS+=		atomic.cpp
SRCS+=		barrier.cpp
SRCS+=		bind.cpp
SRCS+=		charconv.cpp
SRCS+=		chrono.cpp
SRCS+=		condition_variable.cpp
SRCS+=		condition_variable_destructor.cpp
SRCS+=		debug.cpp
SRCS+=		exception.cpp
SRCS+=		filesystem/directory_iterator.cpp
SRCS+=		filesystem/int128_builtins.cpp
SRCS+=		filesystem/operations.cpp
SRCS+=		format.cpp
SRCS+=		functional.cpp
SRCS+=		future.cpp
SRCS+=		hash.cpp
SRCS+=		ios.cpp
SRCS+=		ios.instantiations.cpp
SRCS+=		iostream.cpp
SRCS+=		legacy_debug_handler.cpp
SRCS+=		legacy_pointer_safety.cpp
SRCS+=		locale.cpp
SRCS+=		memory.cpp
SRCS+=		mutex.cpp
SRCS+=		mutex_destructor.cpp
SRCS+=		new.cpp
SRCS+=		optional.cpp
SRCS+=		random.cpp
SRCS+=		random_shuffle.cpp
SRCS+=		regex.cpp
SRCS+=		ryu/d2fixed.cpp
SRCS+=		ryu/d2s.cpp
SRCS+=		ryu/f2s.cpp
SRCS+=		shared_mutex.cpp
SRCS+=		stdexcept.cpp
SRCS+=		string.cpp
SRCS+=		strstream.cpp
SRCS+=		system_error.cpp
SRCS+=		thread.cpp
SRCS+=		typeinfo.cpp
SRCS+=		utility.cpp
SRCS+=		valarray.cpp
SRCS+=		variant.cpp
SRCS+=		vector.cpp

CXXRT_SRCS+=	auxhelper.cc
CXXRT_SRCS+=	dynamic_cast.cc
CXXRT_SRCS+=	exception.cc
CXXRT_SRCS+=	guard.cc
CXXRT_SRCS+=	libelftc_dem_gnu3.c
CXXRT_SRCS+=	memory.cc
CXXRT_SRCS+=	stdexcept.cc
CXXRT_SRCS+=	terminate.cc
CXXRT_SRCS+=	typeinfo.cc

.for _S in ${CXXRT_SRCS}
CLEANFILES+=	cxxrt_${_S}
STATICOBJS+=	cxxrt_${_S:R}.o
cxxrt_${_S}: ${_LIBCXXRTDIR}/${_S} .NOMETA
	ln -sf ${.ALLSRC} ${.TARGET}
.endfor

WARNS?=		0
CFLAGS+=	-isystem ${.CURDIR}
CFLAGS+=	-isystem ${HDRDIR}
CFLAGS+=	-isystem ${SRCDIR}
CFLAGS+=	-isystem ${_LIBCXXRTDIR}
CFLAGS+=	-nostdinc++
CFLAGS+=	-nostdlib
CFLAGS+=	-D_LIBCPP_BUILDING_LIBRARY
CFLAGS+=	-DLIBCXXRT
CFLAGS+=	-ffunction-sections
CFLAGS+=	-fdata-sections
CXXSTD?=	c++20

LIBADD+=	cxxrt

INCSGROUPS+=	STD
STDDIR=		${CXXINCLUDEDIR}
STD_HEADERS+=	__assert
STD_HEADERS+=	__availability
STD_HEADERS+=	__bit_reference
STD_HEADERS+=	__bits
STD_HEADERS+=	__bsd_locale_defaults.h
STD_HEADERS+=	__bsd_locale_fallbacks.h
STD_HEADERS+=	__config
STD_HEADERS+=	__debug
STD_HEADERS+=	__errc
STD_HEADERS+=	__hash_table
STD_HEADERS+=	__locale
STD_HEADERS+=	__mbstate_t.h
STD_HEADERS+=	__mutex_base
STD_HEADERS+=	__node_handle
STD_HEADERS+=	__split_buffer
STD_HEADERS+=	__std_stream
STD_HEADERS+=	__threading_support
STD_HEADERS+=	__tree
STD_HEADERS+=	__tuple
STD_HEADERS+=	__undef_macros
STD_HEADERS+=	algorithm
STD_HEADERS+=	any
STD_HEADERS+=	array
STD_HEADERS+=	atomic
STD_HEADERS+=	barrier
STD_HEADERS+=	bit
STD_HEADERS+=	bitset
STD_HEADERS+=	cassert
STD_HEADERS+=	ccomplex
STD_HEADERS+=	cctype
STD_HEADERS+=	cerrno
STD_HEADERS+=	cfenv
STD_HEADERS+=	cfloat
STD_HEADERS+=	charconv
STD_HEADERS+=	chrono
STD_HEADERS+=	cinttypes
STD_HEADERS+=	ciso646
STD_HEADERS+=	climits
STD_HEADERS+=	clocale
STD_HEADERS+=	cmath
STD_HEADERS+=	codecvt
STD_HEADERS+=	compare
STD_HEADERS+=	complex
STD_HEADERS+=	complex.h
STD_HEADERS+=	concepts
STD_HEADERS+=	condition_variable
STD_HEADERS+=	coroutine
STD_HEADERS+=	csetjmp
STD_HEADERS+=	csignal
STD_HEADERS+=	cstdarg
STD_HEADERS+=	cstdbool
STD_HEADERS+=	cstddef
STD_HEADERS+=	cstdint
STD_HEADERS+=	cstdio
STD_HEADERS+=	cstdlib
STD_HEADERS+=	cstring
STD_HEADERS+=	ctgmath
STD_HEADERS+=	ctime
STD_HEADERS+=	ctype.h
STD_HEADERS+=	cuchar
STD_HEADERS+=	cwchar
STD_HEADERS+=	cwctype
STD_HEADERS+=	deque
STD_HEADERS+=	errno.h
STD_HEADERS+=	exception
STD_HEADERS+=	execution
STD_HEADERS+=	fenv.h
STD_HEADERS+=	filesystem
STD_HEADERS+=	float.h
STD_HEADERS+=	format
STD_HEADERS+=	forward_list
STD_HEADERS+=	fstream
STD_HEADERS+=	functional
STD_HEADERS+=	future
STD_HEADERS+=	initializer_list
STD_HEADERS+=	inttypes.h
STD_HEADERS+=	iomanip
STD_HEADERS+=	ios
STD_HEADERS+=	iosfwd
STD_HEADERS+=	iostream
STD_HEADERS+=	istream
STD_HEADERS+=	iterator
STD_HEADERS+=	latch
STD_HEADERS+=	limits
STD_HEADERS+=	limits.h
STD_HEADERS+=	list
STD_HEADERS+=	locale
STD_HEADERS+=	locale.h
STD_HEADERS+=	map
STD_HEADERS+=	math.h
STD_HEADERS+=	memory
STD_HEADERS+=	mutex
STD_HEADERS+=	new
STD_HEADERS+=	numbers
STD_HEADERS+=	numeric
STD_HEADERS+=	optional
STD_HEADERS+=	ostream
STD_HEADERS+=	queue
STD_HEADERS+=	random
STD_HEADERS+=	ranges
STD_HEADERS+=	ratio
STD_HEADERS+=	regex
STD_HEADERS+=	scoped_allocator
STD_HEADERS+=	semaphore
STD_HEADERS+=	set
STD_HEADERS+=	setjmp.h
STD_HEADERS+=	shared_mutex
STD_HEADERS+=	span
STD_HEADERS+=	sstream
STD_HEADERS+=	stack
STD_HEADERS+=	stdatomic.h
STD_HEADERS+=	stdbool.h
STD_HEADERS+=	stddef.h
STD_HEADERS+=	stdexcept
STD_HEADERS+=	stdint.h
STD_HEADERS+=	stdio.h
STD_HEADERS+=	stdlib.h
STD_HEADERS+=	streambuf
STD_HEADERS+=	string
STD_HEADERS+=	string.h
STD_HEADERS+=	string_view
STD_HEADERS+=	strstream
STD_HEADERS+=	system_error
STD_HEADERS+=	tgmath.h
STD_HEADERS+=	thread
STD_HEADERS+=	tuple
STD_HEADERS+=	type_traits
STD_HEADERS+=	typeindex
STD_HEADERS+=	typeinfo
STD_HEADERS+=	uchar.h
STD_HEADERS+=	unordered_map
STD_HEADERS+=	unordered_set
STD_HEADERS+=	utility
STD_HEADERS+=	valarray
STD_HEADERS+=	variant
STD_HEADERS+=	vector
STD_HEADERS+=	version
STD_HEADERS+=	wchar.h
STD_HEADERS+=	wctype.h
.for hdr in ${STD_HEADERS}
STD+=		${HDRDIR}/${hdr}
.endfor

# Special case for __config_site, which as of libc++ 12.0.0 is generated by
# CMake, and as of 13.0.0 installed side-by-side with__config.
STD+=		${.CURDIR}/__config_site

# Special case for module.modulemap, which as of libc++ 15.0.0 is generated by
# CMake.
STD+=		${.CURDIR}/module.modulemap

RT_HEADERS+=	cxxabi.h
.for hdr in ${RT_HEADERS}
STD+=		${_LIBCXXRTDIR}/${hdr}
.endfor

INCSGROUPS+=	ALG
ALGDIR=		${CXXINCLUDEDIR}/__algorithm
ALG_HEADERS+=	adjacent_find.h
ALG_HEADERS+=	all_of.h
ALG_HEADERS+=	any_of.h
ALG_HEADERS+=	binary_search.h
ALG_HEADERS+=	clamp.h
ALG_HEADERS+=	comp.h
ALG_HEADERS+=	comp_ref_type.h
ALG_HEADERS+=	copy.h
ALG_HEADERS+=	copy_backward.h
ALG_HEADERS+=	copy_if.h
ALG_HEADERS+=	copy_n.h
ALG_HEADERS+=	count.h
ALG_HEADERS+=	count_if.h
ALG_HEADERS+=	equal.h
ALG_HEADERS+=	equal_range.h
ALG_HEADERS+=	fill.h
ALG_HEADERS+=	fill_n.h
ALG_HEADERS+=	find.h
ALG_HEADERS+=	find_end.h
ALG_HEADERS+=	find_first_of.h
ALG_HEADERS+=	find_if.h
ALG_HEADERS+=	find_if_not.h
ALG_HEADERS+=	for_each.h
ALG_HEADERS+=	for_each_n.h
ALG_HEADERS+=	generate.h
ALG_HEADERS+=	generate_n.h
ALG_HEADERS+=	half_positive.h
ALG_HEADERS+=	in_found_result.h
ALG_HEADERS+=	in_fun_result.h
ALG_HEADERS+=	in_in_out_result.h
ALG_HEADERS+=	in_in_result.h
ALG_HEADERS+=	in_out_out_result.h
ALG_HEADERS+=	in_out_result.h
ALG_HEADERS+=	includes.h
ALG_HEADERS+=	inplace_merge.h
ALG_HEADERS+=	is_heap.h
ALG_HEADERS+=	is_heap_until.h
ALG_HEADERS+=	is_partitioned.h
ALG_HEADERS+=	is_permutation.h
ALG_HEADERS+=	is_sorted.h
ALG_HEADERS+=	is_sorted_until.h
ALG_HEADERS+=	iter_swap.h
ALG_HEADERS+=	iterator_operations.h
ALG_HEADERS+=	lexicographical_compare.h
ALG_HEADERS+=	lower_bound.h
ALG_HEADERS+=	make_heap.h
ALG_HEADERS+=	make_projected.h
ALG_HEADERS+=	max.h
ALG_HEADERS+=	max_element.h
ALG_HEADERS+=	merge.h
ALG_HEADERS+=	min.h
ALG_HEADERS+=	min_element.h
ALG_HEADERS+=	min_max_result.h
ALG_HEADERS+=	minmax.h
ALG_HEADERS+=	minmax_element.h
ALG_HEADERS+=	mismatch.h
ALG_HEADERS+=	move.h
ALG_HEADERS+=	move_backward.h
ALG_HEADERS+=	next_permutation.h
ALG_HEADERS+=	none_of.h
ALG_HEADERS+=	nth_element.h
ALG_HEADERS+=	partial_sort.h
ALG_HEADERS+=	partial_sort_copy.h
ALG_HEADERS+=	partition.h
ALG_HEADERS+=	partition_copy.h
ALG_HEADERS+=	partition_point.h
ALG_HEADERS+=	pop_heap.h
ALG_HEADERS+=	prev_permutation.h
ALG_HEADERS+=	push_heap.h
ALG_HEADERS+=	ranges_adjacent_find.h
ALG_HEADERS+=	ranges_all_of.h
ALG_HEADERS+=	ranges_any_of.h
ALG_HEADERS+=	ranges_binary_search.h
ALG_HEADERS+=	ranges_copy.h
ALG_HEADERS+=	ranges_copy_backward.h
ALG_HEADERS+=	ranges_copy_if.h
ALG_HEADERS+=	ranges_copy_n.h
ALG_HEADERS+=	ranges_count.h
ALG_HEADERS+=	ranges_count_if.h
ALG_HEADERS+=	ranges_equal.h
ALG_HEADERS+=	ranges_equal_range.h
ALG_HEADERS+=	ranges_fill.h
ALG_HEADERS+=	ranges_fill_n.h
ALG_HEADERS+=	ranges_find.h
ALG_HEADERS+=	ranges_find_end.h
ALG_HEADERS+=	ranges_find_first_of.h
ALG_HEADERS+=	ranges_find_if.h
ALG_HEADERS+=	ranges_find_if_not.h
ALG_HEADERS+=	ranges_for_each.h
ALG_HEADERS+=	ranges_for_each_n.h
ALG_HEADERS+=	ranges_generate.h
ALG_HEADERS+=	ranges_generate_n.h
ALG_HEADERS+=	ranges_includes.h
ALG_HEADERS+=	ranges_inplace_merge.h
ALG_HEADERS+=	ranges_is_heap.h
ALG_HEADERS+=	ranges_is_heap_until.h
ALG_HEADERS+=	ranges_is_partitioned.h
ALG_HEADERS+=	ranges_is_sorted.h
ALG_HEADERS+=	ranges_is_sorted_until.h
ALG_HEADERS+=	ranges_iterator_concept.h
ALG_HEADERS+=	ranges_lexicographical_compare.h
ALG_HEADERS+=	ranges_lower_bound.h
ALG_HEADERS+=	ranges_make_heap.h
ALG_HEADERS+=	ranges_max.h
ALG_HEADERS+=	ranges_max_element.h
ALG_HEADERS+=	ranges_merge.h
ALG_HEADERS+=	ranges_min.h
ALG_HEADERS+=	ranges_min_element.h
ALG_HEADERS+=	ranges_minmax.h
ALG_HEADERS+=	ranges_minmax_element.h
ALG_HEADERS+=	ranges_mismatch.h
ALG_HEADERS+=	ranges_move.h
ALG_HEADERS+=	ranges_move_backward.h
ALG_HEADERS+=	ranges_none_of.h
ALG_HEADERS+=	ranges_nth_element.h
ALG_HEADERS+=	ranges_partial_sort.h
ALG_HEADERS+=	ranges_partial_sort_copy.h
ALG_HEADERS+=	ranges_partition.h
ALG_HEADERS+=	ranges_partition_copy.h
ALG_HEADERS+=	ranges_partition_point.h
ALG_HEADERS+=	ranges_pop_heap.h
ALG_HEADERS+=	ranges_push_heap.h
ALG_HEADERS+=	ranges_remove.h
ALG_HEADERS+=	ranges_remove_copy.h
ALG_HEADERS+=	ranges_remove_copy_if.h
ALG_HEADERS+=	ranges_remove_if.h
ALG_HEADERS+=	ranges_replace.h
ALG_HEADERS+=	ranges_replace_copy.h
ALG_HEADERS+=	ranges_replace_copy_if.h
ALG_HEADERS+=	ranges_replace_if.h
ALG_HEADERS+=	ranges_reverse.h
ALG_HEADERS+=	ranges_reverse_copy.h
ALG_HEADERS+=	ranges_rotate_copy.h
ALG_HEADERS+=	ranges_search.h
ALG_HEADERS+=	ranges_search_n.h
ALG_HEADERS+=	ranges_set_difference.h
ALG_HEADERS+=	ranges_set_intersection.h
ALG_HEADERS+=	ranges_set_symmetric_difference.h
ALG_HEADERS+=	ranges_set_union.h
ALG_HEADERS+=	ranges_shuffle.h
ALG_HEADERS+=	ranges_sort.h
ALG_HEADERS+=	ranges_sort_heap.h
ALG_HEADERS+=	ranges_stable_partition.h
ALG_HEADERS+=	ranges_stable_sort.h
ALG_HEADERS+=	ranges_swap_ranges.h
ALG_HEADERS+=	ranges_transform.h
ALG_HEADERS+=	ranges_unique.h
ALG_HEADERS+=	ranges_unique_copy.h
ALG_HEADERS+=	ranges_upper_bound.h
ALG_HEADERS+=	remove.h
ALG_HEADERS+=	remove_copy.h
ALG_HEADERS+=	remove_copy_if.h
ALG_HEADERS+=	remove_if.h
ALG_HEADERS+=	replace.h
ALG_HEADERS+=	replace_copy.h
ALG_HEADERS+=	replace_copy_if.h
ALG_HEADERS+=	replace_if.h
ALG_HEADERS+=	reverse.h
ALG_HEADERS+=	reverse_copy.h
ALG_HEADERS+=	rotate.h
ALG_HEADERS+=	rotate_copy.h
ALG_HEADERS+=	sample.h
ALG_HEADERS+=	search.h
ALG_HEADERS+=	search_n.h
ALG_HEADERS+=	set_difference.h
ALG_HEADERS+=	set_intersection.h
ALG_HEADERS+=	set_symmetric_difference.h
ALG_HEADERS+=	set_union.h
ALG_HEADERS+=	shift_left.h
ALG_HEADERS+=	shift_right.h
ALG_HEADERS+=	shuffle.h
ALG_HEADERS+=	sift_down.h
ALG_HEADERS+=	sort.h
ALG_HEADERS+=	sort_heap.h
ALG_HEADERS+=	stable_partition.h
ALG_HEADERS+=	stable_sort.h
ALG_HEADERS+=	swap_ranges.h
ALG_HEADERS+=	transform.h
ALG_HEADERS+=	unique.h
ALG_HEADERS+=	unique_copy.h
ALG_HEADERS+=	unwrap_iter.h
ALG_HEADERS+=	upper_bound.h
.for hdr in ${ALG_HEADERS}
ALG+=		${HDRDIR}/__algorithm/${hdr}
.endfor

INCSGROUPS+=	BIT
BITDIR=		${CXXINCLUDEDIR}/__bit
BIT_HEADERS+=	bit_cast.h
BIT_HEADERS+=	byteswap.h
.for hdr in ${BIT_HEADERS}
BIT+=		${HDRDIR}/__bit/${hdr}
.endfor

INCSGROUPS+=	CHC
CHCDIR=		${CXXINCLUDEDIR}/__charconv
CHC_HEADERS+=	chars_format.h
CHC_HEADERS+=	from_chars_result.h
CHC_HEADERS+=	tables.h
CHC_HEADERS+=	to_chars_base_10.h
CHC_HEADERS+=	to_chars_result.h
.for hdr in ${CHC_HEADERS}
CHC+=		${HDRDIR}/__charconv/${hdr}
.endfor

INCSGROUPS+=	CHR
CHRDIR=		${CXXINCLUDEDIR}/__chrono
CHR_HEADERS+=	calendar.h
CHR_HEADERS+=	convert_to_timespec.h
CHR_HEADERS+=	day.h
CHR_HEADERS+=	duration.h
CHR_HEADERS+=	file_clock.h
CHR_HEADERS+=	hh_mm_ss.h
CHR_HEADERS+=	high_resolution_clock.h
CHR_HEADERS+=	literals.h
CHR_HEADERS+=	month.h
CHR_HEADERS+=	month_weekday.h
CHR_HEADERS+=	monthday.h
CHR_HEADERS+=	steady_clock.h
CHR_HEADERS+=	system_clock.h
CHR_HEADERS+=	time_point.h
CHR_HEADERS+=	weekday.h
CHR_HEADERS+=	year.h
CHR_HEADERS+=	year_month.h
CHR_HEADERS+=	year_month_day.h
CHR_HEADERS+=	year_month_weekday.h
.for hdr in ${CHR_HEADERS}
CHR+=		${HDRDIR}/__chrono/${hdr}
.endfor

INCSGROUPS+=	CMP
CMPDIR=		${CXXINCLUDEDIR}/__compare
CMP_HEADERS+=	common_comparison_category.h
CMP_HEADERS+=	compare_partial_order_fallback.h
CMP_HEADERS+=	compare_strong_order_fallback.h
CMP_HEADERS+=	compare_three_way.h
CMP_HEADERS+=	compare_three_way_result.h
CMP_HEADERS+=	compare_weak_order_fallback.h
CMP_HEADERS+=	is_eq.h
CMP_HEADERS+=	ordering.h
CMP_HEADERS+=	partial_order.h
CMP_HEADERS+=	strong_order.h
CMP_HEADERS+=	synth_three_way.h
CMP_HEADERS+=	three_way_comparable.h
CMP_HEADERS+=	weak_order.h
.for hdr in ${CMP_HEADERS}
CMP+=		${HDRDIR}/__compare/${hdr}
.endfor

INCSGROUPS+=	CON
CONDIR=		${CXXINCLUDEDIR}/__concepts
CON_HEADERS+=	arithmetic.h
CON_HEADERS+=	assignable.h
CON_HEADERS+=	boolean_testable.h
CON_HEADERS+=	class_or_enum.h
CON_HEADERS+=	common_reference_with.h
CON_HEADERS+=	common_with.h
CON_HEADERS+=	constructible.h
CON_HEADERS+=	convertible_to.h
CON_HEADERS+=	copyable.h
CON_HEADERS+=	derived_from.h
CON_HEADERS+=	destructible.h
CON_HEADERS+=	different_from.h
CON_HEADERS+=	equality_comparable.h
CON_HEADERS+=	invocable.h
CON_HEADERS+=	movable.h
CON_HEADERS+=	predicate.h
CON_HEADERS+=	regular.h
CON_HEADERS+=	relation.h
CON_HEADERS+=	same_as.h
CON_HEADERS+=	semiregular.h
CON_HEADERS+=	swappable.h
CON_HEADERS+=	totally_ordered.h
.for hdr in ${CON_HEADERS}
CON+=		${HDRDIR}/__concepts/${hdr}
.endfor

INCSGROUPS+=	COR
CORDIR=		${CXXINCLUDEDIR}/__coroutine
COR_HEADERS+=	coroutine_handle.h
COR_HEADERS+=	coroutine_traits.h
COR_HEADERS+=	noop_coroutine_handle.h
COR_HEADERS+=	trivial_awaitables.h
.for hdr in ${COR_HEADERS}
COR+=		${HDRDIR}/__coroutine/${hdr}
.endfor

INCSGROUPS+=	DBG
DBGDIR=		${CXXINCLUDEDIR}/__debug_utils
DBG_HEADERS+=	randomize_range.h
.for hdr in ${DBG_HEADERS}
DBG+=		${HDRDIR}/__debug_utils/${hdr}
.endfor

INCSGROUPS+=	FS
FSDIR=		${CXXINCLUDEDIR}/__filesystem
FS_HEADERS+=	copy_options.h
FS_HEADERS+=	directory_entry.h
FS_HEADERS+=	directory_iterator.h
FS_HEADERS+=	directory_options.h
FS_HEADERS+=	file_status.h
FS_HEADERS+=	file_time_type.h
FS_HEADERS+=	file_type.h
FS_HEADERS+=	filesystem_error.h
FS_HEADERS+=	operations.h
FS_HEADERS+=	path.h
FS_HEADERS+=	path_iterator.h
FS_HEADERS+=	perm_options.h
FS_HEADERS+=	perms.h
FS_HEADERS+=	recursive_directory_iterator.h
FS_HEADERS+=	space_info.h
FS_HEADERS+=	u8path.h
.for hdr in ${FS_HEADERS}
FS+=		${HDRDIR}/__filesystem/${hdr}
.endfor

INCSGROUPS+=	FMT
FMTDIR=		${CXXINCLUDEDIR}/__format
FMT_HEADERS+=	buffer.h
FMT_HEADERS+=	concepts.h
FMT_HEADERS+=	enable_insertable.h
FMT_HEADERS+=	extended_grapheme_cluster_table.h
FMT_HEADERS+=	format_arg.h
FMT_HEADERS+=	format_arg_store.h
FMT_HEADERS+=	format_args.h
FMT_HEADERS+=	format_context.h
FMT_HEADERS+=	format_error.h
FMT_HEADERS+=	format_fwd.h
FMT_HEADERS+=	format_parse_context.h
FMT_HEADERS+=	format_string.h
FMT_HEADERS+=	format_to_n_result.h
FMT_HEADERS+=	formatter.h
FMT_HEADERS+=	formatter_bool.h
FMT_HEADERS+=	formatter_char.h
FMT_HEADERS+=	formatter_floating_point.h
FMT_HEADERS+=	formatter_integer.h
FMT_HEADERS+=	formatter_integral.h
FMT_HEADERS+=	formatter_output.h
FMT_HEADERS+=	formatter_pointer.h
FMT_HEADERS+=	formatter_string.h
FMT_HEADERS+=	parser_std_format_spec.h
FMT_HEADERS+=	unicode.h
.for hdr in ${FMT_HEADERS}
FMT+=		${HDRDIR}/__format/${hdr}
.endfor

INCSGROUPS+=	FUN
FUNDIR=		${CXXINCLUDEDIR}/__functional
FUN_HEADERS+=	binary_function.h
FUN_HEADERS+=	binary_negate.h
FUN_HEADERS+=	bind.h
FUN_HEADERS+=	bind_back.h
FUN_HEADERS+=	bind_front.h
FUN_HEADERS+=	binder1st.h
FUN_HEADERS+=	binder2nd.h
FUN_HEADERS+=	boyer_moore_searcher.h
FUN_HEADERS+=	compose.h
FUN_HEADERS+=	default_searcher.h
FUN_HEADERS+=	function.h
FUN_HEADERS+=	hash.h
FUN_HEADERS+=	identity.h
FUN_HEADERS+=	invoke.h
FUN_HEADERS+=	is_transparent.h
FUN_HEADERS+=	mem_fn.h
FUN_HEADERS+=	mem_fun_ref.h
FUN_HEADERS+=	not_fn.h
FUN_HEADERS+=	operations.h
FUN_HEADERS+=	perfect_forward.h
FUN_HEADERS+=	pointer_to_binary_function.h
FUN_HEADERS+=	pointer_to_unary_function.h
FUN_HEADERS+=	ranges_operations.h
FUN_HEADERS+=	reference_wrapper.h
FUN_HEADERS+=	unary_function.h
FUN_HEADERS+=	unary_negate.h
FUN_HEADERS+=	unwrap_ref.h
FUN_HEADERS+=	weak_result_type.h
.for hdr in ${FUN_HEADERS}
FUN+=		${HDRDIR}/__functional/${hdr}
.endfor

INCSGROUPS+=	FWD
FWDDIR=		${CXXINCLUDEDIR}/__fwd
FWD_HEADERS+=	span.h
FWD_HEADERS+=	string_view.h
.for hdr in ${FWD_HEADERS}
FWD+=		${HDRDIR}/__fwd/${hdr}
.endfor

INCSGROUPS+=	IOS
IOSDIR=		${CXXINCLUDEDIR}/__ios
IOS_HEADERS+=	fpos.h
.for hdr in ${IOS_HEADERS}
IOS+=		${HDRDIR}/__ios/${hdr}
.endfor

INCSGROUPS+=	IT
ITDIR=		${CXXINCLUDEDIR}/__iterator
IT_HEADERS+=	access.h
IT_HEADERS+=	advance.h
IT_HEADERS+=	back_insert_iterator.h
IT_HEADERS+=	bounded_iter.h
IT_HEADERS+=	common_iterator.h
IT_HEADERS+=	concepts.h
IT_HEADERS+=	counted_iterator.h
IT_HEADERS+=	data.h
IT_HEADERS+=	default_sentinel.h
IT_HEADERS+=	distance.h
IT_HEADERS+=	empty.h
IT_HEADERS+=	erase_if_container.h
IT_HEADERS+=	front_insert_iterator.h
IT_HEADERS+=	incrementable_traits.h
IT_HEADERS+=	indirectly_comparable.h
IT_HEADERS+=	insert_iterator.h
IT_HEADERS+=	istream_iterator.h
IT_HEADERS+=	istreambuf_iterator.h
IT_HEADERS+=	iter_move.h
IT_HEADERS+=	iter_swap.h
IT_HEADERS+=	iterator.h
IT_HEADERS+=	iterator_traits.h
IT_HEADERS+=	mergeable.h
IT_HEADERS+=	move_iterator.h
IT_HEADERS+=	move_sentinel.h
IT_HEADERS+=	next.h
IT_HEADERS+=	ostream_iterator.h
IT_HEADERS+=	ostreambuf_iterator.h
IT_HEADERS+=	permutable.h
IT_HEADERS+=	prev.h
IT_HEADERS+=	projected.h
IT_HEADERS+=	readable_traits.h
IT_HEADERS+=	reverse_access.h
IT_HEADERS+=	reverse_iterator.h
IT_HEADERS+=	size.h
IT_HEADERS+=	sortable.h
IT_HEADERS+=	unreachable_sentinel.h
IT_HEADERS+=	wrap_iter.h
.for hdr in ${IT_HEADERS}
IT+=		${HDRDIR}/__iterator/${hdr}
.endfor

INCSGROUPS+=	MEM
MEMDIR=		${CXXINCLUDEDIR}/__memory
MEM_HEADERS+=	addressof.h
MEM_HEADERS+=	allocate_at_least.h
MEM_HEADERS+=	allocation_guard.h
MEM_HEADERS+=	allocator.h
MEM_HEADERS+=	allocator_arg_t.h
MEM_HEADERS+=	allocator_traits.h
MEM_HEADERS+=	assume_aligned.h
MEM_HEADERS+=	auto_ptr.h
MEM_HEADERS+=	compressed_pair.h
MEM_HEADERS+=	concepts.h
MEM_HEADERS+=	construct_at.h
MEM_HEADERS+=	pointer_traits.h
MEM_HEADERS+=	ranges_construct_at.h
MEM_HEADERS+=	ranges_uninitialized_algorithms.h
MEM_HEADERS+=	raw_storage_iterator.h
MEM_HEADERS+=	shared_ptr.h
MEM_HEADERS+=	swap_allocator.h
MEM_HEADERS+=	temporary_buffer.h
MEM_HEADERS+=	uninitialized_algorithms.h
MEM_HEADERS+=	unique_ptr.h
MEM_HEADERS+=	uses_allocator.h
MEM_HEADERS+=	voidify.h
.for hdr in ${MEM_HEADERS}
MEM+=		${HDRDIR}/__memory/${hdr}
.endfor

INCSGROUPS+=    NUM
NUMDIR=		${CXXINCLUDEDIR}/__numeric
NUM_HEADERS+=	accumulate.h
NUM_HEADERS+=	adjacent_difference.h
NUM_HEADERS+=	exclusive_scan.h
NUM_HEADERS+=	gcd_lcm.h
NUM_HEADERS+=	inclusive_scan.h
NUM_HEADERS+=	inner_product.h
NUM_HEADERS+=	iota.h
NUM_HEADERS+=	midpoint.h
NUM_HEADERS+=	partial_sum.h
NUM_HEADERS+=	reduce.h
NUM_HEADERS+=	transform_exclusive_scan.h
NUM_HEADERS+=	transform_inclusive_scan.h
NUM_HEADERS+=	transform_reduce.h
.for hdr in ${NUM_HEADERS}
NUM+=		${HDRDIR}/__numeric/${hdr}
.endfor

INCSGROUPS+=	RND
RNDDIR=		${CXXINCLUDEDIR}/__random
RND_HEADERS+=	bernoulli_distribution.h
RND_HEADERS+=	binomial_distribution.h
RND_HEADERS+=	cauchy_distribution.h
RND_HEADERS+=	chi_squared_distribution.h
RND_HEADERS+=	clamp_to_integral.h
RND_HEADERS+=	default_random_engine.h
RND_HEADERS+=	discard_block_engine.h
RND_HEADERS+=	discrete_distribution.h
RND_HEADERS+=	exponential_distribution.h
RND_HEADERS+=	extreme_value_distribution.h
RND_HEADERS+=	fisher_f_distribution.h
RND_HEADERS+=	gamma_distribution.h
RND_HEADERS+=	generate_canonical.h
RND_HEADERS+=	geometric_distribution.h
RND_HEADERS+=	independent_bits_engine.h
RND_HEADERS+=	is_seed_sequence.h
RND_HEADERS+=	is_valid.h
RND_HEADERS+=	knuth_b.h
RND_HEADERS+=	linear_congruential_engine.h
RND_HEADERS+=	log2.h
RND_HEADERS+=	lognormal_distribution.h
RND_HEADERS+=	mersenne_twister_engine.h
RND_HEADERS+=	negative_binomial_distribution.h
RND_HEADERS+=	normal_distribution.h
RND_HEADERS+=	piecewise_constant_distribution.h
RND_HEADERS+=	piecewise_linear_distribution.h
RND_HEADERS+=	poisson_distribution.h
RND_HEADERS+=	random_device.h
RND_HEADERS+=	ranlux.h
RND_HEADERS+=	seed_seq.h
RND_HEADERS+=	shuffle_order_engine.h
RND_HEADERS+=	student_t_distribution.h
RND_HEADERS+=	subtract_with_carry_engine.h
RND_HEADERS+=	uniform_int_distribution.h
RND_HEADERS+=	uniform_random_bit_generator.h
RND_HEADERS+=	uniform_real_distribution.h
RND_HEADERS+=	weibull_distribution.h
.for hdr in ${RND_HEADERS}
RND+=		${HDRDIR}/__random/${hdr}
.endfor

INCSGROUPS+=	RNG
RNGDIR=		${CXXINCLUDEDIR}/__ranges
RNG_HEADERS+=	access.h
RNG_HEADERS+=	all.h
RNG_HEADERS+=	common_view.h
RNG_HEADERS+=	concepts.h
RNG_HEADERS+=	copyable_box.h
RNG_HEADERS+=	counted.h
RNG_HEADERS+=	dangling.h
RNG_HEADERS+=	data.h
RNG_HEADERS+=	drop_view.h
RNG_HEADERS+=	empty.h
RNG_HEADERS+=	empty_view.h
RNG_HEADERS+=	enable_borrowed_range.h
RNG_HEADERS+=	enable_view.h
RNG_HEADERS+=	filter_view.h
RNG_HEADERS+=	iota_view.h
RNG_HEADERS+=	join_view.h
RNG_HEADERS+=	lazy_split_view.h
RNG_HEADERS+=	non_propagating_cache.h
RNG_HEADERS+=	owning_view.h
RNG_HEADERS+=	range_adaptor.h
RNG_HEADERS+=	rbegin.h
RNG_HEADERS+=	ref_view.h
RNG_HEADERS+=	rend.h
RNG_HEADERS+=	reverse_view.h
RNG_HEADERS+=	single_view.h
RNG_HEADERS+=	size.h
RNG_HEADERS+=	subrange.h
RNG_HEADERS+=	take_view.h
RNG_HEADERS+=	transform_view.h
RNG_HEADERS+=	view_interface.h
RNG_HEADERS+=	views.h
RNG_HEADERS+=	zip_view.h
.for hdr in ${RNG_HEADERS}
RNG+=		${HDRDIR}/__ranges/${hdr}
.endfor

INCSGROUPS+=	STR
STRDIR=		${CXXINCLUDEDIR}/__string
STR_HEADERS+=	char_traits.h
STR_HEADERS+=	extern_template_lists.h
.for hdr in ${STR_HEADERS}
STR+=		${HDRDIR}/__string/${hdr}
.endfor

INCSGROUPS+=	THR
THRDIR=		${CXXINCLUDEDIR}/__thread
THR_HEADERS+=	poll_with_backoff.h
THR_HEADERS+=	timed_backoff_policy.h
.for hdr in ${THR_HEADERS}
THR+=		${HDRDIR}/__thread/${hdr}
.endfor

INCSGROUPS+=	TTR
TTRDIR=		${CXXINCLUDEDIR}/__type_traits
TTR_HEADERS+=	add_const.h
TTR_HEADERS+=	add_cv.h
TTR_HEADERS+=	add_lvalue_reference.h
TTR_HEADERS+=	add_pointer.h
TTR_HEADERS+=	add_rvalue_reference.h
TTR_HEADERS+=	add_volatile.h
TTR_HEADERS+=	aligned_storage.h
TTR_HEADERS+=	aligned_union.h
TTR_HEADERS+=	alignment_of.h
TTR_HEADERS+=	apply_cv.h
TTR_HEADERS+=	common_reference.h
TTR_HEADERS+=	common_type.h
TTR_HEADERS+=	conditional.h
TTR_HEADERS+=	conjunction.h
TTR_HEADERS+=	copy_cv.h
TTR_HEADERS+=	copy_cvref.h
TTR_HEADERS+=	decay.h
TTR_HEADERS+=	disjunction.h
TTR_HEADERS+=	enable_if.h
TTR_HEADERS+=	extent.h
TTR_HEADERS+=	has_unique_object_representation.h
TTR_HEADERS+=	has_virtual_destructor.h
TTR_HEADERS+=	integral_constant.h
TTR_HEADERS+=	is_abstract.h
TTR_HEADERS+=	is_aggregate.h
TTR_HEADERS+=	is_arithmetic.h
TTR_HEADERS+=	is_array.h
TTR_HEADERS+=	is_assignable.h
TTR_HEADERS+=	is_base_of.h
TTR_HEADERS+=	is_bounded_array.h
TTR_HEADERS+=	is_callable.h
TTR_HEADERS+=	is_class.h
TTR_HEADERS+=	is_compound.h
TTR_HEADERS+=	is_const.h
TTR_HEADERS+=	is_constant_evaluated.h
TTR_HEADERS+=	is_constructible.h
TTR_HEADERS+=	is_convertible.h
TTR_HEADERS+=	is_copy_assignable.h
TTR_HEADERS+=	is_copy_constructible.h
TTR_HEADERS+=	is_core_convertible.h
TTR_HEADERS+=	is_default_constructible.h
TTR_HEADERS+=	is_destructible.h
TTR_HEADERS+=	is_empty.h
TTR_HEADERS+=	is_enum.h
TTR_HEADERS+=	is_final.h
TTR_HEADERS+=	is_floating_point.h
TTR_HEADERS+=	is_function.h
TTR_HEADERS+=	is_fundamental.h
TTR_HEADERS+=	is_integral.h
TTR_HEADERS+=	is_literal_type.h
TTR_HEADERS+=	is_member_function_pointer.h
TTR_HEADERS+=	is_member_object_pointer.h
TTR_HEADERS+=	is_member_pointer.h
TTR_HEADERS+=	is_move_assignable.h
TTR_HEADERS+=	is_move_constructible.h
TTR_HEADERS+=	is_nothrow_assignable.h
TTR_HEADERS+=	is_nothrow_constructible.h
TTR_HEADERS+=	is_nothrow_convertible.h
TTR_HEADERS+=	is_nothrow_copy_assignable.h
TTR_HEADERS+=	is_nothrow_copy_constructible.h
TTR_HEADERS+=	is_nothrow_default_constructible.h
TTR_HEADERS+=	is_nothrow_destructible.h
TTR_HEADERS+=	is_nothrow_move_assignable.h
TTR_HEADERS+=	is_nothrow_move_constructible.h
TTR_HEADERS+=	is_null_pointer.h
TTR_HEADERS+=	is_object.h
TTR_HEADERS+=	is_pod.h
TTR_HEADERS+=	is_pointer.h
TTR_HEADERS+=	is_polymorphic.h
TTR_HEADERS+=	is_primary_template.h
TTR_HEADERS+=	is_reference.h
TTR_HEADERS+=	is_reference_wrapper.h
TTR_HEADERS+=	is_referenceable.h
TTR_HEADERS+=	is_same.h
TTR_HEADERS+=	is_scalar.h
TTR_HEADERS+=	is_scoped_enum.h
TTR_HEADERS+=	is_signed.h
TTR_HEADERS+=	is_signed_integer.h
TTR_HEADERS+=	is_standard_layout.h
TTR_HEADERS+=	is_trivial.h
TTR_HEADERS+=	is_trivially_assignable.h
TTR_HEADERS+=	is_trivially_constructible.h
TTR_HEADERS+=	is_trivially_copy_assignable.h
TTR_HEADERS+=	is_trivially_copy_constructible.h
TTR_HEADERS+=	is_trivially_copyable.h
TTR_HEADERS+=	is_trivially_default_constructible.h
TTR_HEADERS+=	is_trivially_destructible.h
TTR_HEADERS+=	is_trivially_move_assignable.h
TTR_HEADERS+=	is_trivially_move_constructible.h
TTR_HEADERS+=	is_unbounded_array.h
TTR_HEADERS+=	is_union.h
TTR_HEADERS+=	is_unsigned.h
TTR_HEADERS+=	is_unsigned_integer.h
TTR_HEADERS+=	is_valid_expansion.h
TTR_HEADERS+=	is_void.h
TTR_HEADERS+=	is_volatile.h
TTR_HEADERS+=	lazy.h
TTR_HEADERS+=	make_32_64_or_128_bit.h
TTR_HEADERS+=	make_signed.h
TTR_HEADERS+=	make_unsigned.h
TTR_HEADERS+=	nat.h
TTR_HEADERS+=	negation.h
TTR_HEADERS+=	promote.h
TTR_HEADERS+=	rank.h
TTR_HEADERS+=	remove_all_extents.h
TTR_HEADERS+=	remove_const.h
TTR_HEADERS+=	remove_cv.h
TTR_HEADERS+=	remove_cvref.h
TTR_HEADERS+=	remove_extent.h
TTR_HEADERS+=	remove_pointer.h
TTR_HEADERS+=	remove_reference.h
TTR_HEADERS+=	remove_volatile.h
TTR_HEADERS+=	type_identity.h
TTR_HEADERS+=	type_list.h
TTR_HEADERS+=	underlying_type.h
TTR_HEADERS+=	void_t.h
.for hdr in ${TTR_HEADERS}
TTR+=		${HDRDIR}/__type_traits/${hdr}
.endfor

INCSGROUPS+=	UTL
UTLDIR=		${CXXINCLUDEDIR}/__utility
UTL_HEADERS+=	as_const.h
UTL_HEADERS+=	auto_cast.h
UTL_HEADERS+=	cmp.h
UTL_HEADERS+=	declval.h
UTL_HEADERS+=	exchange.h
UTL_HEADERS+=	forward.h
UTL_HEADERS+=	in_place.h
UTL_HEADERS+=	integer_sequence.h
UTL_HEADERS+=	move.h
UTL_HEADERS+=	pair.h
UTL_HEADERS+=	piecewise_construct.h
UTL_HEADERS+=	priority_tag.h
UTL_HEADERS+=	rel_ops.h
UTL_HEADERS+=	swap.h
UTL_HEADERS+=	to_underlying.h
UTL_HEADERS+=	transaction.h
UTL_HEADERS+=	unreachable.h
.for hdr in ${UTL_HEADERS}
UTL+=		${HDRDIR}/__utility/${hdr}
.endfor

INCSGROUPS+=	VAR
VARDIR=	${CXXINCLUDEDIR}/__variant
VAR_HEADERS+=	monostate.h
.for hdr in ${VAR_HEADERS}
VAR+=		${HDRDIR}/__variant/${hdr}
.endfor

INCSGROUPS+=	EXP
EXPDIR=		${CXXINCLUDEDIR}/experimental
EXP_HEADERS+=	__config
EXP_HEADERS+=	__memory
EXP_HEADERS+=	algorithm
EXP_HEADERS+=	coroutine
EXP_HEADERS+=	deque
EXP_HEADERS+=	forward_list
EXP_HEADERS+=	functional
EXP_HEADERS+=	iterator
EXP_HEADERS+=	list
EXP_HEADERS+=	map
EXP_HEADERS+=	memory_resource
EXP_HEADERS+=	propagate_const
EXP_HEADERS+=	regex
EXP_HEADERS+=	set
EXP_HEADERS+=	simd
EXP_HEADERS+=	string
EXP_HEADERS+=	type_traits
EXP_HEADERS+=	unordered_map
EXP_HEADERS+=	unordered_set
EXP_HEADERS+=	utility
EXP_HEADERS+=	vector
.for hdr in ${EXP_HEADERS}
EXP+=		${HDRDIR}/experimental/${hdr}
.endfor

INCSGROUPS+=	EXT
EXTDIR=		${CXXINCLUDEDIR}/ext
EXT_HEADERS+=	__hash
EXT_HEADERS+=	hash_map
EXT_HEADERS+=	hash_set
.for hdr in ${EXT_HEADERS}
EXT+=		${HDRDIR}/ext/${hdr}
.endfor

.include <bsd.lib.mk>
