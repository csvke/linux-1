#===============================================================================
# local variables
#===============================================================================
EXTRA_CFLAGS += -I$(srctree)/drivers/hisilicon/sdk/common-include \
		-I$(srctree)/drivers/hisilicon/common/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/include \
		-I$(srctree)/drivers/hisilicon/msp/include \
		-I$(srctree)/drivers/hisilicon/sdk/msp-api/gpio \
		-I$(srctree)/drivers/hisilicon/msp/gpio

EXTRA_CFLAGS += -Werror

MOD_NAME := hi_gpio

$(MOD_NAME)-y := drv_gpio_intf.o	\
		 drv_gpio.o

obj-y += $(MOD_NAME).o
