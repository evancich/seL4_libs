/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

/*
 * Copyright 2018, Intelligent Automation, Inc.
 * This software was developed in part under Air Force contract number FA8750-15-C-0066 and DARPA 
 *  contract number 140D6318C0001.
 * This software was released under DARPA, public release number 0.6.
 * This software may be distributed and modified according to the terms of the BSD 2-Clause license.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(IAI_BSD)
 */


#pragma once

#include <stdarg.h>

/* prototype all the syscalls we implement */
long sys_set_thread_area(va_list ap);
long sys_set_tid_address(va_list ap);
long sys_sched_yield(va_list ap);
long sys_exit(va_list ap);
long sys_rt_sigprocmask(va_list ap);
long sys_gettid(va_list ap);
long sys_getpid(va_list ap);
long sys_tgkill(va_list ap);
long sys_tkill(va_list ap);
long sys_exit_group(va_list ap);
long sys_open(va_list ap);
long sys_openat(va_list ap);
long sys_close(va_list ap);
long sys_readv(va_list ap);
long sys_read(va_list ap);
long sys_ioctl(va_list ap);
long sys_prlimit64(va_list ap);
long sys_lseek(va_list ap);
long sys__llseek(va_list ap);
long sys_access(va_list ap);
long sys_brk(va_list ap);
long sys_mmap2(va_list ap);
long sys_mmap(va_list ap);
long sys_mremap(va_list ap);
long sys_writev(va_list ap);
long sys_madvise(va_list ap);
long sys_nanosleep(va_list ap);

