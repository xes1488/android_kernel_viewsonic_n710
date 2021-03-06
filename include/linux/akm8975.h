/*
 * Definitions for akm8975 compass chip.
 */
#ifndef AKM8975_H
#define AKM8975_H

#include <linux/ioctl.h>

/*! \name AK8975 operation mode
 \anchor AK8975_Mode
 Defines an operation mode of the AK8975.*/
/*! @{*/
#define AK8975_MODE_SNG_MEASURE   0x01
#define	AK8975_MODE_SELF_TEST     0x08
#define	AK8975_MODE_FUSE_ACCESS   0x0F
#define	AK8975_MODE_POWER_DOWN    0x00
/*! @}*/

#define RBUFF_SIZE			8	/* Rx buffer size */
#define AKM_NUM_SENSORS		3
#define SENSOR_DATA_SIZE	8

/*! \name AK8975 register address
\anchor AK8975_REG
Defines a register address of the AK8975.*/
/*! @{*/
#define AK8975_REG_WIA		0x00
#define AK8975_REG_INFO		0x01
#define AK8975_REG_ST1		0x02
#define AK8975_REG_HXL		0x03
#define AK8975_REG_HXH		0x04
#define AK8975_REG_HYL		0x05
#define AK8975_REG_HYH		0x06
#define AK8975_REG_HZL		0x07
#define AK8975_REG_HZH		0x08
#define AK8975_REG_ST2		0x09
#define AK8975_REG_CNTL		0x0A
#define AK8975_REG_RSV		0x0B
#define AK8975_REG_ASTC		0x0C
#define AK8975_REG_TS1		0x0D
#define AK8975_REG_TS2		0x0E
#define AK8975_REG_I2CDIS	0x0F
/*! @}*/

/*! \name AK8975 fuse-rom address
\anchor AK8975_FUSE
Defines a read-only address of the fuse ROM of the AK8975.*/
/*! @{*/
#define AK8975_FUSE_ASAX	0x10
#define AK8975_FUSE_ASAY	0x11
#define AK8975_FUSE_ASAZ	0x12
/*! @}*/

#define AKMIO                   0xB2 //0xA1

/* IOCTLs for AKM library */
#define ECS_IOCTL_WRITE                 _IOW(AKMIO, 0x01, char*)			//0x02, char[5]
#define ECS_IOCTL_READ                  _IOWR(AKMIO, 0x02, char*)			//0x03, char[5]

#define ECS_IOCTL_SET_MODE              _IOW(AKMIO, 0x04, short)
//#define ECS_IOCTL_GETDATA               _IOR(AKMIO, 0x05, char[RBUFF_SIZE])	//0x08
#define ECS_IOCTL_GETDATA               _IOR(AKMIO, 0x05, char[SENSOR_DATA_SIZE])
#define ECS_IOCTL_SET_YPR               _IOW(AKMIO, 0x06, short[12])		//0x0C
#define ECS_IOCTL_GET_OPEN_STATUS       _IOR(AKMIO, 0x07, int)				//0x0D
#define ECS_IOCTL_GET_CLOSE_STATUS      _IOR(AKMIO, 0x08, int)				//0x0E
//#define ECS_IOCTL_GET_DELAY             _IOR(AKMIO, 0x30, short)			//0x30
#define ECS_IOCTL_GET_DELAY             _IOR(AKMIO, 0x30, long long int[AKM_NUM_SENSORS])
#define ECS_IOCTL_GET_ACCEL             _IOR(AKMIO, 0x31, short[3])

/* IOCTLs for APPs */
#define ECS_IOCTL_APP_SET_MFLAG		_IOW(AKMIO, 0x11, short)
#define ECS_IOCTL_APP_GET_MFLAG		_IOW(AKMIO, 0x12, short)
#define ECS_IOCTL_APP_SET_AFLAG		_IOW(AKMIO, 0x13, short)
#define ECS_IOCTL_APP_GET_AFLAG		_IOR(AKMIO, 0x14, short)
#define ECS_IOCTL_APP_SET_DELAY		_IOW(AKMIO, 0x18, long long int[AKM_NUM_SENSORS]) //short
#define ECS_IOCTL_APP_GET_DELAY		ECS_IOCTL_GET_DELAY
/* Set raw magnetic vector flag */
#define ECS_IOCTL_APP_SET_MVFLAG	_IOW(AKMIO, 0x19, short)
/* Get raw magnetic vector flag */
#define ECS_IOCTL_APP_GET_MVFLAG	_IOR(AKMIO, 0x1A, short)
#define ECS_IOCTL_APP_SET_TFLAG         _IOR(AKMIO, 0x15, short)
#define ECS_IOCTL_APP_SET_ACCEL		_IOW(AKMIO, 0x1B, short[3])

struct akm8975_platform_data {
	int intr;

	int (*init)(void);
	void (*exit)(void);
	int (*power_on)(void);
	int (*power_off)(void);
};

#endif

