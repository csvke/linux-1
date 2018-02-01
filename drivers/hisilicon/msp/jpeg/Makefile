#===============================================================================
# module name
#===============================================================================
TARGET := jpeg

#===============================================================================
# local variables
#===============================================================================
EXTRA_CFLAGS += -I$(srctree)/drivers/hisilicon/sdk/common-include \
		-I$(srctree)/drivers/hisilicon/common/include \
		-I$(srctree)/drivers/hisilicon/msp/include \
		-I$(srctree)/drivers/hisilicon/msp/$(TARGET)/include \
		-I$(srctree)/drivers/hisilicon/msp/$(TARGET)/src

EXTRA_CFLAGS += -I$(srctree)/drivers/hisilicon/msp/$(TARGET)/grc_cmm_inc

EXTRA_CFLAGS += -Werror

#=====================================================================================
#the jpeg use version
#=====================================================================================
EXTRA_CFLAGS += -DCONFIG_HI_SDK_JPEG_VERSION
#EXTRA_CFLAGS += -DCONFIG_HI_FPGA_JPEG_VERSION


#=====================================================================================
#the platform version
#=====================================================================================
EXTRA_CFLAGS += -DCONFIG_GFX_STB_SDK

#=====================================================================================
#ddr and stride is 256bytes align
#=====================================================================================

EXTRA_CFLAGS += -DCONFIG_GFX_MMU_SUPPORT
EXTRA_CFLAGS += -DCONFIG_GFX_MMU_CLOCK

#=====================================================================================
#the chip env version
#=====================================================================================
#=====================================================================================
#use kernel signal,not use mutex
#=====================================================================================
#EXTRA_CFLAGS += -DCONFIG_JPEG_USE_KERNEL_SIGNAL

#================================================================================
#select the complie file
#================================================================================
MOD_NAME := hi_$(TARGET)

obj-y += $(MOD_NAME).o

$(MOD_NAME)-y :=    src/jpeg_drv_hal.o		\
		    src/jpeg_drv_proc.o		\
		    src/jpeg_drv_suspend.o	\
		    src/jpeg_drv_osr.o

$(MOD_NAME)-y +=    src_dec/jpeg_drv_parse.o	\
		    src_dec/jpeg_drv_table.o	\
		    src_dec/jpeg_drv_setpara.o	\
		    src_dec/jpeg_drv_dec.o	\
		    src_dec/jpeg_drv_harddec.o
