/* Copyright (c) 2009-2010, 2013 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/delay.h>

static const struct of_device_id mt7668_match_table[] = {
	{ .compatible = "mtk,mt7668-wifi", },
	{}
};

static int wifi_reset_gpio;

static int wifi_power_probe(struct platform_device *pdev)
{
	int ret = 0;

	dev_dbg(&pdev->dev, "%s\n", __func__);

	if (!pdev->dev.of_node) {
		dev_err(&pdev->dev, "device node not set\n");
		return -ENODEV;
	}

	wifi_reset_gpio = of_get_named_gpio(pdev->dev.of_node,
					  "mtk,wifi-reset-gpio", 0);
	if (wifi_reset_gpio < 0) {
		pr_err("wifi-reset-gpio not available");
		return wifi_reset_gpio;
	}

	ret = gpio_request(wifi_reset_gpio, "wifi sys_rst_n");
	if (ret) {
		pr_err("%s: unable to request gpio %d (%d)\n",
			__func__, wifi_reset_gpio, ret);
		return ret;
	}

	/* When booting up, assert WiFi reset pin */
	ret = gpio_direction_output(wifi_reset_gpio, 0);
	if (ret) {
		pr_err("%s: Unable to set direction\n", __func__);
		return ret;
	}

	mdelay(10);

	/* de-assert WiFi reset pin */
	ret = gpio_direction_output(wifi_reset_gpio, 1);
	if (ret) {
		pr_err("%s: Unable to set direction\n", __func__);
		return ret;
	}

	return ret;
}

static int wifi_power_remove(struct platform_device *pdev)
{
	dev_dbg(&pdev->dev, "%s\n", __func__);

	return 0;
}

static struct platform_driver wifi_power_driver = {
	.probe = wifi_power_probe,
	.remove = wifi_power_remove,
	.driver = {
		.name = "wifi_power",
		.owner = THIS_MODULE,
		.of_match_table = mt7668_match_table,
	},
};

static int __init wifi_power_init(void)
{
	int ret;

	ret = platform_driver_register(&wifi_power_driver);
	return ret;
}

static void __exit wifi_power_exit(void)
{
	platform_driver_unregister(&wifi_power_driver);
}

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("HiSilicon WiFi power control driver");
MODULE_VERSION("1.00");

module_init(wifi_power_init);
module_exit(wifi_power_exit);
