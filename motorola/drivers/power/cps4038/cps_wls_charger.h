/*
 * Copyright © 2020, ConvenientPower
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef __CPS_WLS_CHARGER_H__
#define __CPS_WLS_CHARGER_H__
#include <linux/workqueue.h>
#include <linux/thermal.h>
#include "mtk_charger_intf.h"
#include <linux/power/moto_chg_tcmd.h>
#include "moto_wlc_intf.h"
#include "moto_wls_auth2.0.h"

#define CPS_WLS_FAIL    -1
#define CPS_WLS_SUCCESS 0
struct tags_bootmode {
	uint32_t size;
	uint32_t tag;
	uint32_t bootmode;
	uint32_t boottype;
};
/*****************************************************************************
 *  CMD REG
 ****************************************************************************/
#define ADDR_BUFFER0        0x20000800
#define ADDR_BUFFER1        0x20001000
#define ADDR_CMD            0x20001800
#define ADDR_FLAG           0x20001804
#define ADDR_BUF_SIZE       0x20001808
#define ADDR_FW_VER         0x2000180C

#define PGM_BUFFER0         0x10
#define PGM_BUFFER1         0x20
#define PGM_BUFFER2         0x30
#define PGM_BUFFER3         0x40
#define PGM_BUFFER0_1       0x50
#define PGM_ERASER_0        0x60
#define PGM_ERASER_1        0x70
#define PGM_WR_FLAG         0x80

#define CACL_CRC_APP        0x90
#define CACL_CRC_TEST       0xB0

#define PGM_ADDR_SET        0xC0

#define RUNNING             0x66
#define PASS                0x55
#define FAIL                0xAA
#define ILLEGAL             0x40

//****************system mode***************
#define SYS_MODE_BACK_POWER 1
#define SYS_MODE_TX         2
#define SYS_MODE_RX         3

/*rx中断定义*/
#define RX_INT_POWER_ON         (0x01<<0)
#define RX_INT_LDO_OFF              (0x01<<1)
#define RX_INT_LDO_ON                (0x01<<2)
#define RX_INT_READY                    (0x01<<3)
#define RX_INT_FSK_ACK                (0x01<<4)
#define RX_INT_FSK_TIMEOUT         (0x01<<5)
#define RX_INT_FSK_PKT         (0x01<<6)
#define RX_INT_OVP              (0x01<<7)
#define RX_INT_AC_LOSS      (0x01<<8)
#define RX_INT_OVP_TO        (0x01<<9)
#define RX_INT_AC_SHORT        (0x01<<10)
#define RX_INT_OTP              (0x01<<11)
#define RX_INT_SR_OCP              (0x01<<12)
#define RX_INT_OCP              (0x01<<13)
#define RX_INT_HOCP             (0x01<<14)
#define RX_INT_SCP              (0x01<<15)
#define RX_INT_SR_SW_R         (0x01<<16)
#define RX_INT_SR_SW_F     (0x01<<17)
#define RX_INT_FC_OK     (0x01<<18)
#define RX_INT_HS_OK     (0x01<<19)
#define RX_INT_HTP     (0x01<<20)
#define RX_INT_HS_FAIL     (0x01<<21)
#define RX_INT_FC_FAIL     (0x01<<22)
#define RX_INT_NEGO_POWER_READY     (0x01<<23)
#define RX_INT_PT     (0x01<<24)
/*rx命令定义*/
#define RX_CMD_SEND_DATA         (0x01<<0)
#define RX_CMD_FAST_CHARGING         (0x01<<1)
#define RX_CMD_SEND_EPT         (0x01<<2)
#define RX_CMD_RESET_SYS        (0x01<<3)

/*tx中断定义*/
#define TX_INT_PING             (0x01<<0)
#define TX_INT_SSP              (0x01<<1)
#define TX_INT_IDP              (0x01<<2)
#define TX_INT_CFGP             (0x01<<3)
#define TX_INT_ASK_PKT          (0x01<<4)
#define TX_INT_EPT              (0x01<<5)
#define TX_INT_RPP_TO           (0x01<<6)
#define TX_INT_CEP_TO           (0x01<<7)
#define TX_INT_AC_DET           (0x01<<8)
#define TX_INT_INIT                (0x01<<9)
#define TX_INT_ASK_ALL             (0x01<<10)
#define TX_INT_RPP_TYPE_ERR         (0x01<<11)
#define TX_INT_RP_ASK_ACK      (0x01<<12)
#define TX_INT_PING_OVP             (0x01<<13)

/*tx命令定义*/
#define TX_CMD_CRC_CHECK         (0x01<<0)
#define TX_CMD_ENTER_TX_MODE    (0x01<<1)
#define TX_CMD_EXIT_TX_MODE     (0x01<<2)
#define TX_CMD_SEND_FSK         (0x01<<3)
#define TX_CMD_RESET_SYS        (0x01<<4)

/*tx功能定义*/
//#define TX_RESERVE1_EN          (0x01<<0)
//#define TX_FULL_BRI             (0x01<<1)
///#define TX_RESERVE2_EN          (0x01<<2)

/*tx EPT定义*/
#define EPT_VRECT_OVP                (0x01<<13)
#define EPT_SR_OCP                 (0x01<<12)
#define EPT_POCP                (0x01<<11)
#define EPT_OTP                 (0x01<<10)
#define EPT_FOD                 (0x01<<9)
#define EPT_UVP                 (0x01<<8)
#define EPT_OVP                 (0x01<<7)
#define EPT_OCP                 (0x01<<6)
#define EPT_RPP_TO              (0x01<<5)
#define EPT_CEP_TO              (0x01<<4)
//#define EPT_RCV_EPT             (0x01<<3)
//#define EPT_SSP                 (0x01<<2)
#define EPT_RCV_EPT                 (0x01<<3)
#define EPT_AC_DET              (0x01<<2)
#define EPT_POVP              (0x01<<1)
#define EPT_WRONG_PACKET        (0x01<<0)

#define CPS_PROGRAM_BUFFER_SIZE   512         /*64 128 256 512*/

#define RX_CMD_SEND_ASK         (0x01<<0)
#define RX_CMD_RESERVE2         (0x01<<1)
#define RX_CMD_SEND_EPT         (0x01<<2)
#define RX_CMD_RESET_SYS        (0x01<<3)

//#define AP_SYS_CONTROL_BASE_ADDR   0x20001D40
//#define AP_TX_CONFIG_BASE_ADDR     0x20001E00
//#define AP_TX_CONTROL_BASE_ADDR    0x20001E40
//#define AP_TX_REPORT_BASE_ADDR     0x20001E80
//#define AP_RX_CONFIG_BASE_ADDR     0x20001F00
//#define AP_RX_CONTROL_BASE_ADDR    0x20001F40
//#define AP_RX_REPORT_BASE_ADDR     0x20001F80
#define RX_FOD_GAIN_LEN 16
#define RX_FOD_CURR_LEN 7


#define _CPS_MASK(BITS, POS) \
	((unsigned char)(((1 << (BITS)) - 1) << (POS)))

#define CPS_MASK(LEFT_BIT_POS, RIGHT_BIT_POS) \
		_CPS_MASK((LEFT_BIT_POS) - (RIGHT_BIT_POS) + 1, \
				(RIGHT_BIT_POS))

static uint32_t bpp_fod_array_w_folio[RX_FOD_GAIN_LEN] =
{80, 11, 80, 11, 80, 11, 80, 11, 80, 11, 80, 11, 80, 11, 80, 11};

static uint32_t epp_fod_array_w_folio[RX_FOD_GAIN_LEN] =
{120, 32, 120, 24, 120, 21, 120, 21, 120, 19, 120, 18, 120, 17, 120, 17};
typedef enum
{
    CPS_COMM_REG_CHIP_ID,
    CPS_COMM_REG_FW_VER,
    CPS_COMM_REG_SYS_MODE,
    CPS_COMM_REG_INT_EN,
    CPS_COMM_REG_INT_FLAG,
    CPS_COMM_REG_INT_CLR,
    CPS_COMM_REG_CMD,
    CPS_COMM_REG_MAX
}cps_comm_reg_e;

/*****************************************************************************
 *  Log
 ****************************************************************************/
#define CPS_LOG_NONE    0
#define CPS_LOG_ERR     1
#define CPS_LOG_DEBG    2
#define CPS_LOG_FULL    3
    
#define ENABLE_CPS_LOG CPS_LOG_FULL
    
#define cps_wls_log(num, fmt, args...) \
    do { \
            if (ENABLE_CPS_LOG >= (int)num) \
                pr_err(fmt, ##args); \
    } while (0)
    
/*-------------------------------------------------------------------*/
//struct moto_wls_chg_ops {
//	void *data;
//	void (*wls_current_select)(int  *icl, int *vbus);
//	void (*wls_set_battery_soc)(int uisoc);
//};

struct cps_wls_chrg_chip {
    struct i2c_client *client;
    struct device *dev;
    struct regmap *regmap;
   struct regmap *regmap32;
    char *name;
    struct power_supply *wl_psy;
    struct power_supply *batt_psy;
    struct power_supply *usb_psy;
    struct power_supply *dc_psy;
    struct power_supply_desc wl_psd;
    struct power_supply_config wl_psc; 
    struct power_supply_desc batt_psd;    
    struct power_supply_desc usb_psd;
    struct power_supply_desc dc_psd;
    struct pinctrl *cps_pinctrl;
    struct pinctrl_state *cps_gpio_active;
    struct pinctrl_state *cps_gpio_suspend;

    struct wakeup_source *cps_wls_wake_lock;
    struct mutex   irq_lock;
    struct mutex   i2c_lock;
    int state;
    int wls_charge_int;
    int cps_wls_irq;
    int reg_addr;
    int reg_data;
    int rx_ovp;
    int rx_ocp;
    int rx_opp;
    int rx_ht_thl;
    int rx_vout_target;
    int rx_ept_rsn;
    int rx_irect;
    int rx_vrect;
    int rx_vout;
    int rx_die_temp;
    int rx_ntc;
    int rx_neg_power;
    int rx_neg_protocol;
    int command_flag;

    u32 wls_curr_max;

    unsigned long flags;
    int rx_ldo_on;
    int wls_online;
    int wls_det_int;
    int wls_det_irq;
    const char *wls_fw_name;
    uint32_t wls_fw_version;
	/* alarm timer */
	struct alarm wls_rx_timer;
	struct timespec64 end_time;
    unsigned int rx_polling_ns;
    uint32_t tx_mode;
    uint32_t wls_input_curr_max;
    uint32_t folio_mode;
    bool rx_connected;
    struct moto_chg_tcmd_client wls_tcmd_client;
    struct moto_wls_chg_ops  wls_chg_ops;
    Sys_Op_Mode mode_type;
    uint32_t MaxV;
    uint32_t MaxI;
    uint32_t chip_id;
    bool factory_wls_en;

	wait_queue_head_t  wait_que;
	bool wls_rx_check_thread_timeout;
	struct wakeup_source *rx_check_wakelock;
    struct workqueue_struct *wls_wq;
    struct delayed_work fw_update_work;
    struct delayed_work	bpp_icl_work;
    uint32_t bootmode;
    struct thermal_cooling_device *tcd;
    bool ntc_thermal;
    bool fw_uploading;
    struct charger_device *chg1_dev;
    bool chip_state;
    bool rx_int_ready;
    bool bpp_icl_done;

    /*wls pen*/
#ifdef SMART_PEN_SUPPORT
    struct moto_wls_pen_ops  wls_pen_ops;
    uint32_t cps_pen_status;
    uint32_t cps_pen_soc;
    bool pen_power_on;
#endif
    int wls_mode_select;
    int fan_speed;
    int light_level;
    int wlc_status;
    uint32_t wlc_tx_power;
    int cable_ready_wait_count;
    bool moto_stand;
    bool factory_mode;
    struct moto_chg_tcmd_client *chg_tcmd_client;

    bool rx_offset;
    int enable_rx_offset_detect;
    bool enable_rod;
    int rx_offset_detect_count;
    int rod_stop_battery_soc;
    Sys_Op_Mode qi_mode_type;
    int thermal_icl;
    struct delayed_work	offset_detect_work;
    ktime_t rx_start_ktime;
    bool rod_stop;
    int rx_vout_set;
    int rx_vout_threshold;
};

typedef enum ept_reason
{
    EPT_UNKONWN = 0,
    EPT_CC,
    EPT_IF,
    EPT_OT,
    EPT_OV,
    EPT_OC,
    EPT_BF,
    EPT_RES1,
    EPT_NP,
    EPT_RES2,
    EPT_NF,
    EPT_RS,
}ept_reason_e;

static void wls_rx_start_timer(struct cps_wls_chrg_chip *info);
static void cps_rx_online_check(struct cps_wls_chrg_chip *chg);
static int cps_wls_set_status(int status);
static void cps_wls_current_select(int  *icl, int *vbus, bool *cable_ready);
static void cps_init_charge_hardware(void);
static void cps_epp_current_select(int  *icl, int *vbus);
int cps_wls_get_ldo_on(void);
int cps_wls_sysfs_notify(const char *attr);
#endif
