#===============================================================================
# local variables
#===============================================================================
EXTRA_CFLAGS += -Werror

EXTRA_CFLAGS += -I$(srctree)/drivers/hisilicon/sdk/common-include \
		-I$(srctree)/drivers/hisilicon/common/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/include \
		-I$(srctree)/drivers/hisilicon/msp/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/pvr/include \
		-I$(srctree)/drivers/hisilicon/sdk/ha_codec-include


MOD_NAME := hi_pvr

obj-y += $(MOD_NAME).o

$(MOD_NAME)-y	:=  drv_pvr_intf.o
