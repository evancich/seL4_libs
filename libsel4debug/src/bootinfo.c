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


#include <autoconf.h>

#include <stdio.h>

#include <sel4/sel4.h>
#include <utils/util.h>

#ifdef CONFIG_USER_DEBUG_BUILD
void
debug_print_bootinfo(seL4_BootInfo *info)
{

    ZF_LOGI("Node %lu of %lu", (long)info->nodeID, (long)info->numNodes);
    ZF_LOGI("IOPT levels:     %u", (int)info->numIOPTLevels);
    ZF_LOGI("IPC buffer:      %p", info->ipcBuffer);
    ZF_LOGI("Empty slots:     [%lu --> %lu)", (long)info->empty.start, (long)info->empty.end);
    ZF_LOGI("sharedFrames:    [%lu --> %lu)", (long)info->sharedFrames.start, (long)info->sharedFrames.end);
    ZF_LOGI("userImageFrames: [%lu --> %lu)", (long)info->userImageFrames.start, (long)info->userImageFrames.end);
    ZF_LOGI("userImagePaging: [%lu --> %lu)", (long)info->userImagePaging.start, (long)info->userImagePaging.end);
    ZF_LOGI("untypeds:        [%lu --> %lu)", (long)info->untyped.start, (long)info->untyped.end);
    ZF_LOGI("Initial thread domain: %u\n", (int)info->initThreadDomain);
    ZF_LOGI("Initial thread cnode size: %u", info->initThreadCNodeSizeBits);
    ZF_LOGI("List of untypeds");
    ZF_LOGI("------------------");
    ZF_LOGI("Paddr    | Size   | Device");

    int sizes[CONFIG_WORD_SIZE] = {0};
    for (int i = 0; i < CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS && i < (info->untyped.end - info->untyped.start); i++) {
        int index = info->untypedList[i].sizeBits;
        assert(index < ARRAY_SIZE(sizes));
        sizes[index]++;
        ZF_LOGI("%p | %zu | %d", (void*)info->untypedList[i].paddr, (size_t)info->untypedList[i].sizeBits, (int)info->untypedList[i].isDevice);
    }

    ZF_LOGI("Untyped summary\n");
    uint64_t totalsize = 0;
    uint64_t tempsize = 0;
    for (int i = 0; i < ARRAY_SIZE(sizes); i++) {
        if (sizes[i] != 0) {
            printf("%d untypeds of size %d, %d\n", sizes[i], i, (1<<i));
	    tempsize = 1;
	    tempsize = tempsize << i;
	    tempsize *= sizes[i];
	    totalsize += tempsize;
        }
    }
    totalsize /= (uint64_t)(1024*1024);
    printf("Grand total free memory = %d MB\n", (int)totalsize);
}

#endif  /* CONFIG_USER_DEBUG_BUILD */
