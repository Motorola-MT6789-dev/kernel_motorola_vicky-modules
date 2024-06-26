#ifndef _KTD3136_REG_H_
#define _KTD3136_REG_H_

#include <linux/version.h>

/*********************************************************
 *
 * kernel version
 *
 ********************************************************/
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
#define KERNEL_ABOVE_4_14
#endif

#undef pr_debug
#define pr_debug pr_info

/*********************************************************
 *
 * kernel version
 *
 ********************************************************/
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
#define KERNEL_ABOVE_4_14
#endif

#define KTD3136_REG_CONFILCT
#ifdef KTD3136_REG_CONFILCT
#define KTD3136_REG_REAL	0x36
#endif

#define MAX_BRIGHTNESS                  (2047)
#define BANK_NONE                       0x00
#define REG_DEV_ID                      0x00
#define REG_SW_RESET                    0x01
#define REG_MODE                        0x02
#define REG_CONTROL                     0x03
#define REG_RATIO_LSB                   0x04
#define REG_RATIO_MSB                   0x05
#define REG_PWM                         0x06
#define REG_RAMP_ON                     0x07
#define REG_TRANS_RAMP                  0x08
#define REG_FLASH_SETTING               0x09
#define REG_STATUS                      0x0A
#define BIT_CH3_FAULT                   BIT(7)
#define BIT_CH2_FAULT                   BIT(6)
#define BIT_CH1_FAULT                   BIT(5)
#define BIT_FLASH_TIMEOUT               BIT(4)
#define BIT_OVP                         BIT(3)
#define BIT_UVLO                        BIT(2)
#define BIT_OCP                         BIT(1)
#define BIT_THERMAL_SHUTDOWN            BIT(0)

#define RESET_CONDITION_BITS	 (BIT_CH3_FAULT | BIT_CH2_FAULT | BIT_CH1_FAULT | BIT_OVP | BIT_OCP)

/********************************************
 * Register Access
 *******************************************/
#define KTD3136_REG_ACCESS_MAX				0x20
#define REG_NONE_ACCESS					0
#define REG_RD_ACCESS					(1 << 0)
#define REG_WR_ACCESS					(1 << 1)

const unsigned char ktd3136_reg_access[] = {
	[REG_DEV_ID] = REG_RD_ACCESS,
	[REG_SW_RESET] = REG_RD_ACCESS,
	[REG_MODE] = REG_RD_ACCESS,
	[REG_CONTROL] = REG_RD_ACCESS,
	[REG_RATIO_LSB] = REG_RD_ACCESS|REG_WR_ACCESS,
	[REG_RATIO_MSB] = REG_RD_ACCESS|REG_WR_ACCESS,
	[REG_PWM] = REG_RD_ACCESS|REG_WR_ACCESS,
	[REG_RAMP_ON] = REG_RD_ACCESS|REG_WR_ACCESS,
	[REG_TRANS_RAMP] = REG_RD_ACCESS|REG_WR_ACCESS,
	[REG_FLASH_SETTING] = REG_RD_ACCESS,
	[REG_STATUS] = REG_RD_ACCESS,
};

int ktd3136_brightness_table_reg4[256] = {0x01,0x02,0x04,0x04,0x07,0x02,0x00,0x06,0x04,0x02,0x03,0x04,0x05,0x06,0x02,0x06,0x02,
			0x06,0x02,0x06,0x02,0x06,0x02,0x04,0x05,0x06,0x05,0x03,0x00,0x05,0x02,0x06,0x02,0x06,0x02,0x06,0x02,0x06,0x02,0x06,
			0x02,0x06,0x02,0x06,0x02,0x06,0x01,0x04,0x07,0x02,0x05,0x00,0x03,0x06,0x01,0x04,0x07,0x02,0x05,0x00,0x03,0x05,0x07,
			0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x00,0x01,0x02,0x03,
			0x04,0x05,0x06,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x06,0x05,
			0x04,0x03,0x02,0x01,0x00,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x07,0x05,0x03,0x01,0x07,0x05,0x03,0x01,0x07,0x05,0x03,
			0x01,0x07,0x05,0x03,0x00,0x05,0x02,0x07,0x04,0x01,0x06,0x03,0x00,0x05,0x02,0x07,0x04,0x01,0x06,0x03,0x00,0x05,0x02,
			0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,0x03,0x07,
			0x03,0x07,0x03,0x07,0x03,0x06,0x01,0x04,0x07,0x02,0x05,0x00,0x03,0x06,0x01,0x04,0x07,0x02,0x05,0x00,0x03,0x06,0x01,
			0x04,0x07,0x02,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,
			0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,0x03,0x05,0x07,0x01,
			0x03,0x05,0x07,0x01,0x03,0x04,0x05,0x06,0x07};

int ktd3136_brightness_table_reg5[256] = {0x00,0x06,0x0C,0x11,0x15,0x1A,0x1E,0x21,0x25,0x29,0x2C,0x2F,0x32,0x35,0x38,0x3A,0x3D,
			0x3F,0x42,0x44,0x47,0x49,0x4C,0x4E,0x50,0x52,0x54,0x56,0x58,0x59,0x5B,0x5C,0x5E,0x5F,0x61,0x62,0x64,0x65,0x67,0x68,
			0x6A,0x6B,0x6D,0x6E,0x70,0x71,0x73,0x74,0x75,0x77,0x78,0x7A,0x7B,0x7C,0x7E,0x7F,0x80,0x82,0x83,0x85,0x86,0x87,0x88,
			0x8A,0x8B,0x8C,0x8D,0x8F,0x90,0x91,0x92,0x94,0x95,0x96,0x97,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,0xA1,0xA2,0xA3,0xA4,
			0xA5,0xA6,0xA7,0xA8,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xB9,0xBA,0xBB,
			0xBC,0xBD,0xBE,0xBF,0xC0,0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC6,0xC7,0xC8,0xC9,0xC9,0xCA,0xCB,0xCC,0xCC,0xCD,0xCE,
			0xCF,0xCF,0xD0,0xD1,0xD2,0xD2,0xD3,0xD3,0xD4,0xD5,0xD5,0xD6,0xD7,0xD7,0xD8,0xD8,0xD9,0xDA,0xDA,0xDB,0xDC,0xDC,0xDD,
			0xDD,0xDE,0xDE,0xDF,0xDF,0xE0,0xE0,0xE1,0xE1,0xE2,0xE2,0xE3,0xE3,0xE4,0xE4,0xE5,0xE5,0xE6,0xE6,0xE7,0xE7,0xE8,0xE8,
			0xE9,0xE9,0xEA,0xEA,0xEB,0xEB,0xEC,0xEC,0xEC,0xED,0xED,0xEE,0xEE,0xEE,0xEF,0xEF,0xEF,0xF0,0xF0,0xF1,0xF1,0xF1,0xF2,
			0xF2,0xF2,0xF3,0xF3,0xF3,0xF4,0xF4,0xF4,0xF4,0xF5,0xF5,0xF5,0xF5,0xF6,0xF6,0xF6,0xF6,0xF7,0xF7,0xF7,0xF7,0xF8,0xF8,
			0xF8,0xF8,0xF9,0xF9,0xF9,0xF9,0xFA,0xFA,0xFA,0xFA,0xFB,0xFB,0xFB,0xFB,0xFC,0xFC,0xFC,0xFC,0xFD,0xFD,0xFD,0xFD,0xFE,
			0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

enum backlight_exp_current_align {
	ALIGN_NONE,
	ALIGN_BL_MAPPING_450
};

struct ktd3136_data {
	struct led_classdev led_dev;
	struct i2c_client *client;
	struct i2c_adapter *adapter;
	unsigned short addr;
	struct mutex		lock;
	struct work_struct	work;
	enum led_brightness brightness;
#ifdef CONFIG_FB
	struct notifier_block fb_notif;
#endif
	bool enable;
	u8 pwm_cfg;
	u8 boost_ctl;
	u8 full_scale_current;
	bool brt_code_enable;
	u16 *brt_code_table;
	int hwen_gpio;
	bool pwm_mode;
	unsigned int map_type;
	unsigned int led_current_align;
	unsigned int reg_ctrl_val;
	bool using_lsb;
	bool skip_first_trans;
	bool reset_trans_delay;
	unsigned int pwm_period;
	unsigned int full_scale_led;
	unsigned int ramp_on_time;
	unsigned int ramp_off_time;
	unsigned int pwm_trans_dim;
	unsigned int i2c_trans_dim;
	unsigned int channel;
	unsigned int ovp_level;
	unsigned int frequency;
	unsigned int default_brightness;
	unsigned int max_brightness;
	unsigned int induct_current;
	unsigned int flash_current;
	unsigned int flash_timeout;

};

#endif
