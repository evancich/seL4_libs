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
 * This software was released under DARPA, public release number XXXXXXXX (to be updated once approved)
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

/* This file provides various small API wrappers either for simple convenience, backwards compatibility,
   or abstracting different kernel versions */

#include <sel4/sel4.h>
#include <sel4utils/mcs_api.h>

/* Helper for generating a guard. The guard itself is a bitpacked data structure, but is passed
   to invocations as a raw word */
static inline seL4_Word api_make_guard_word(seL4_Word guard, seL4_Word guard_size) {
    /* the bitfield generated _new function will assert that our chosen values fit
       into the datastructure so there is no need for us to do anything beyond
       blindly pass them in */
    //NO, we like blidly passing them in...
    //seL4_Word tw = guard << 6;
    //return tw | (guard_size&0x3f);
    return seL4_CNode_CapData_new(guard, guard_size).words[0];
}

/* Helper for making an empty guard. Typically a guard matches zeroes and is effectively acting
   as a skip. This is a convenience wrapper and api_make_guard_word */
static inline seL4_Word api_make_guard_skip_word(seL4_Word guard_size) {
    //return guard_size&0x3f;
    return api_make_guard_word(0, guard_size);
}
