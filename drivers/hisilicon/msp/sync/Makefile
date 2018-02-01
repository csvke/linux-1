#===============================================================================
# local variables
#===============================================================================
EXTRA_CFLAGS := -Werror
EXTRA_CFLAGS += -I$(srctree)/drivers/hisilicon/sdk/common-include \
		-I$(srctree)/drivers/hisilicon/common/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/include \
		-I$(srctree)/drivers/hisilicon/msp/include \
		-I$(srctree)/drivers/hisilicon/sdk/ha_codec-include


MOD_NAME := hi_sync

obj-y += $(MOD_NAME).o

$(MOD_NAME)-y	:=  drv_sync.o		 \
		    drv_sync_intf.o	 \
		    drv_sync_intf_k.o	 \
		    drv_sync_stc.o
