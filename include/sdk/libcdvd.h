#ifndef _LIBCDVD_H
#define _LIBCDVD_H

// CdInit Mode
#define SCECdINIT 0 // disk chk
#define SCECdINoD 1 // disk no chk
#define SCECdEXIT 5 // cdvd exit

// Media mode
#define SCECdCD 1
#define SCECdDVD 2

/*
 * Macros for Error code
 */
#define SCECdErFAIL                                                                                                    \
    -1                      /* sceCdGetError()�֐���                                                           \
                                            ���s�Ɏ��s����      */
#define SCECdErNO 0x00      /* No Error                         */
#define SCECdErEOM 0x32     /* �Đ����ɍŊO���ɒB����	    */
#define SCECdErTRMOPN 0x31  /* �Đ����ɊW��������ꂽ  	    */
#define SCECdErREAD 0x30    /* �ǂ݂�������肪�ɔ�������	    */
#define SCECdErPRM 0x22     /* ��ʃR�}���h�̃p�����[�^�Ɍ��   */
#define SCECdErILI 0x21     /* �]�����w�肪���		    */
#define SCECdErIPI 0x20     /* �]���J�n�A�h���X�w�肪���	    */
#define SCECdErCUD 0x14     /* �h���C�u���̃f�B�X�N�ɂ͕s�K��   */
#define SCECdErNORDY 0x13   /* �R�}���h������		    */
#define SCECdErNODISC 0x12  /* �f�B�X�N������		    */
#define SCECdErOPENS 0x11   /* �W���J���Ă���		    */
#define SCECdErCMD 0x10     /* ���T�|�[�g�̃R�}���h���s	    */
#define SCECdErABRT 0x01    /* �R�}���h�������ɃA�{�[�g���s	    */
#define SCECdErREADCF 0xfd  /* �ǂ݂����R�}���h���s�Ɏ��s�����B */
#define SCECdErREADCFR 0xfe /* �ǂ݂����R�}���h���s�Ɏ��s�����B */
#define SCECdErSFRMTNG 0x38 /* �R�}���h�ƃZ�N�^�̃t�H�[�}�b�g�� */
                            /* �قȂ�B			    */

/*
 * Macros for sceCdGetDiskType()
 */
#define SCECdIllgalMedia 0xff
#define SCECdIllegalMedia 0xff
/* ILIMEDIA (Illegal Media)
    Disc �� ��PS/��PS2 Disc �ł��邱�Ƃ�\�킷�B */
#define SCECdDVDV 0xfe
/* DVDV (DVD Video)
    Disc �� ��PS/��PS2 �ł��� DVD Video �ł��邱�Ƃ�\�킷�B*/
#define SCECdCDDA 0xfd
/* CDDA (CD DA)
    Disc �� ��PS/��PS2 �ł��� DA �g���b�N�܂ނ��Ƃ�\�킷�B*/
#define SCECdPS2DVD 0x14
/* PS2DVD  Disc �� PS2 �p DVD �ł��邱�Ƃ�\�킷�B*/
#define SCECdPS2CDDA 0x13
/* PS2CDDA Disc �� PS2 �p CD �ł��� DA �g���b�N�܂ނ��Ƃ�\�킷�B*/
#define SCECdPS2CD 0x12
/* PS2CD   Disc �� PS2 �p CD �ł��� DA �g���b�N�܂܂Ȃ����Ƃ�\�킷�B*/
#define SCECdPSCDDA 0x11
/* PSCDDA  Disc �� PS �p CD �ł��� DA �g���b�N�܂ނ��Ƃ�\�킷�B */
#define SCECdPSCD 0x10
/* PSCD    Disc �� PS �p CD �ł��� DA �g���b�N�܂܂Ȃ����Ƃ�\�킷�B*/
#define SCECdDETCT 0x01
/* DETCT (Detecting) Disc ���ʓ��쒆��\�킷�B*/
#define SCECdNODISC 0x00
/* NODISC (No disc) Disc �������Ă��Ȃ���Ԃ�\�킷�B*/
#define SCECdUNKNOWN 0x05
/* UNKNOWN          Disc ���ʕs�\	*/
#define SCECdGDTFUNCFAIL (-1)
/* FUNCFAIL			�֐��Ăяo�����s */

int sceCdInit(int init_mode);
int sceCdMmode(int media);
int sceCdGetError(void);
int sceCdGetDiskType(void);

#endif
