#===============================================================================
# local variables
#===============================================================================
EXTRA_CFLAGS += -Werror

EXTRA_CFLAGS += -I$(srctree)/drivers/hisilicon/sdk/common-include \
		-I$(srctree)/drivers/hisilicon/common/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/include \
		-I$(srctree)/drivers/hisilicon/msp/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/higo/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/tde/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/jpge/include \
		-I$(srctree)/drivers/hisilicon/msp/jpge/include \
		-I$(srctree)/drivers/hisilicon/msp/adsp/adsp_v1_1/include

EXTRA_CFLAGS += -DHI_OMX_SUPPORT

ifeq ($(CFG_HI_CIPLUS_SUPPORT),y)
    EXTRA_CFLAGS += -DHI_CIPLUS_SUPPORT

    ifeq ($(CFG_HI_CI_DEV_CIMAX),y)
    EXTRA_CFLAGS += -DHI_CI_DEV_CIMAX
    endif

    ifeq ($(CFG_HI_CI_DEV_CIMAXPLUS),y)
    EXTRA_CFLAGS += -DHI_CI_DEV_CIMAXPLUS
    endif

    ifeq ($(CFG_HI_CI_DEV_HICI),y)
    EXTRA_CFLAGS += -DHI_CI_DEV_HICI
    endif
endif

MOD_NAME := hi_base

obj-y += $(MOD_NAME).o

$(MOD_NAME)-y	:=  hi_init.o
