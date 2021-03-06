/***************************************************************

	����䥩� � �������᪮� ������⥪� HSCLI.DLL

	������ (1.1.6.16)

 �����:
 ========
 22.10.04	���⮢� ��ਠ��

 ***************************************************************/
#ifndef HSCLI_H_INCLUDED
#define HSCLI_H_INCLUDED

/* ��� ����஥��� 䨪⨢��� DLL*/
#ifdef HSCLI_DUMMY_DLL
#define HSCLI_DLL
#define HSCLI_EOF { return 0; }
#else
#define HSCLI_EOF ;
#endif

#ifdef __cplusplus
# define HSCLI_PFX extern "C"
#else
# define HSCLI_PFX
#endif

/* �㭪樨, ��ᯮ���㥬� �� DLL */
#if defined(HYCFG_SOLARIS) || defined(HYCFG_LINUX)
# define HSCLI_FUN(type) HSCLI_PFX type
# define HSCLI_CBK
#elif defined(HYCFG_NETWARE)
# ifdef HSCLI_DLL
#  define HSCLI_FUN(type) HSCLI_PFX type _export
# define HSCLI_CBK
# else
#  define HSCLI_FUN(type) HSCLI_PFX type
# define HSCLI_CBK
# endif
#elif defined(HYCFG_WIN32)
# ifdef HSCLI_DLL
#  define HSCLI_FUN(type) HSCLI_PFX type __export __stdcall
#  define HSCLI_CBK __stdcall
# else
#  define HSCLI_FUN(type) HSCLI_PFX type __stdcall
#  define HSCLI_CBK __stdcall
# endif
#else
# error !os
#endif


/* �訡�� �����쭮� ��� */
#define	SQL_RTL_LCL_REMOTE		-20001	/* �訡�� �裡 */
#define	SQL_RTL_LCL_USER_BREAK		-20002	/* ��ࠡ�⪠ ��ࢠ�� ���짮��⥫�� */
#define	SQL_RTL_LCL_NO_INIT		-20003	/* �� ���樠����஢��� */
#define	SQL_RTL_LCL_GENERAL_ERROR	-20004	/* ��㣠� �訡�� */
#define SQL_RTL_LCL_BUSY		-20005	/* �।���� ������ �� �����襭� */
#define	SQL_RTL_LCL_NO_MEMORY		-20006	/* ���� ����� */
#define SQL_RTL_LCL_TOO_MANY_SESSIONS	-20007	/* ����� ��ᨩ */
#define	SQL_RTL_LCL_INV_ARG		-20008	/* ���ࠢ���� ��㬥�� */
#define SQL_RTL_LCL_TOO_OLD_SERVER	-20009	/* ���� �ࢥ� */

/***************************************************************
	���� ������ � ����⠭��
 ***************************************************************/
/* �����䨪��� ������ */
typedef int hcHSTMT;
/* �����䨪��� ᮥ������� */
typedef int hcHDB;
/* ����� ���� */
typedef int hcFLD;
/* ����� ����� � ⠡��� ��� १���� */
typedef long hcRECNO;
/* ��ࠡ��稪 ����� */
typedef long hcRHANDLE;
/* ��� �訡�� */
#ifndef HSCLI_DLL
typedef int hcERR;
#endif

/* �㭪�� ��ࠡ�⪨ ⥪�⮢�� ᮮ�饭�� �ࢥ� */
typedef void HSCLI_CBK hcSqlCbkSrvMsgT(hcHDB conn, int is_err);
typedef void HSCLI_CBK hcSqlCbkStmtSrvMsgT(hcHDB conn, hcHSTMT stmt, int is_err);
/* �㭪�� ��ࠡ�⪨ Usersend */
typedef void HSCLI_CBK hcSqlCbkSrvUserSendT(hcHDB conn, int usertype);
typedef void HSCLI_CBK hcSqlCbkStmtSrvUserSendT(hcHDB conn, hcHSTMT stmt, int usertype);

/* ��ࠬ���� ���樠����樨 */
typedef struct hcSqlParmT
{	unsigned	size;		/* ������ �������� */
} hcSqlParmT;

/***************************************************************
	�㭪樨
 ***************************************************************/
/* ���樠����஢��� ��������� ���� */
HSCLI_FUN(hcERR) hcSqlInit(
  hcSqlParmT	*arg)		/* ��㬥��� ���樠����樨 */
  	HSCLI_EOF
/* �������� ࠡ��� */
HSCLI_FUN(hcERR) hcSqlDone(void)
  	HSCLI_EOF
/* �஢���� �����襭�� ���樠����樨 */
HSCLI_FUN(hcERR) hcSqlCheckInit(void)
	HSCLI_EOF

/* ������� ᮥ������� */
HSCLI_FUN(hcERR) hcSqlAllocConnect(
  hcHDB		*pdb)		/* ���������� */
  	HSCLI_EOF
/* �᢮������ ᮥ������� */
HSCLI_FUN(hcERR) hcSqlFreeConnect(
  hcHDB		hdb)		/* ���������� */
  	HSCLI_EOF
/* ��⠭����� ��� � �ࢥ஬ �� */
HSCLI_FUN(hcERR) hcSqlConnect(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*server,
  const char	*user,
  const char	*password)
  	HSCLI_EOF
/* ����ࢠ�� ��� � �ࢥ஬ �� */
HSCLI_FUN(hcERR) hcSqlDisconnect(
  hcHDB		hdb)		/* �����䨪��� ᮥ������� */
  	HSCLI_EOF
/* ������� ���ଠ�� �� ᮥ������� */
#define HSCLI_CONN_SRV_PATH	101	/* ��ப� ᮥ������� (char[]) */
#define HSCLI_CONN_SRV_VERS	102	/* ����� �ࢥ� (double) */
#define HSCLI_CONN_SRV_VERS2	103	/* ����� �ࢥ� (char[]) */
#define HSCLI_CONN_USER_INFO	151	/* ���ଠ�� ���짮��⥫� (long) */
#define HSCLI_CONN_LCLADDR	152	/* ���� (������) (char[]) */
#define HSCLI_CONN_RMTADDR	153	/* ���� (�ࢥ�) (char[]) */
HSCLI_FUN(hcERR) hcSqlGetConnectAttr(
  hcHDB		h,		/* �����䨪��� ᮥ������� */
  unsigned	option,		/* ����� */
  int		pos,		/* ������ */
  void		*pValue,	/* ���� ��� ���祭�� */
  unsigned	size,		/* � ��� ࠧ��� */
  unsigned	*cnt)		/* ᪮�쪮 ���⮢ ����ᠫ� � ���� */
  	HSCLI_EOF
#define HSCLI_ATTR_FLD_VERBOSE		1001	/* [conn/stmt] ����७��� ���ଠ�� � ����� (int) */
#define HSCLI_ATTR_CONN_USER_INFO	1002	/* [conn/stmt] ���ଠ�� ���짮��⥫� (long) */
#define	HSCLI_ATTR_CBK_SRVMSG		1100	/* [conn] �㭪�� ��ࠡ�⪨ ᮮ�饭�� �ࢥ� (hcSqlCbkSrvMsgT*) */
#define	HSCLI_ATTR_CBK_SRVUSERSEND	1101	/* [conn] �㭪�� ��ࠡ�⪨ ���짮��⥫�᪨� ᮮ�饭�� �ࢥ� (hcSqlCbkSrvUserSendT*) */
#define	HSCLI_ATTR_CBK_STMT_SRVMSG	1102	/* [stmt] �㭪�� ��ࠡ�⪨ ᮮ�饭�� �ࢥ� (hcSqlCbkStmtSrvMsgT*) */
#define	HSCLI_ATTR_CBK_STMT_SRVUSERSEND	1103	/* [stmt] �㭪�� ��ࠡ�⪨ ���짮��⥫�᪨� ᮮ�饭�� �ࢥ� (hcSqlCbkStmtSrvUserSendT*) */
/* ��������� ��ࠬ��஢ ᮥ������� */
HSCLI_FUN(hcERR) hcSqlSetConnectAttr(
  hcHDB		h,		/* �����䨪��� ᮥ������� */
  unsigned	option,		/* ����� */
  void		*pValue,	/* ���祭�� (int/long) ��� ���� ���祭�� */
  unsigned	size)		/* ������ ���祭�� � ����� ��� 0, �᫨ ��।����� int/long */
  	HSCLI_EOF
/* ������� ��஫� ���짮��⥫�
 * �������: = 0  - �ᯥ�, < 0 - �訡�� */
HSCLI_FUN(hcERR) hcSqlAlterPassword(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ���짮��⥫� */
  const char	*oldpswd, 	/* ���� ��஫� */
  const char	*newpswd) 	/* ���� ��஫� */
	HSCLI_EOF

/* ������� ���짮��⥫�
 * �������: = 0  - �ᯥ�, < 0 - �訡�� */
HSCLI_FUN(hcERR) hcSqlCreateUser(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ���짮��⥫� */
  const char	*pswd, 		/* ��஫� */
  const char	*profile, 	/* ��䨫� */
  const char	*startup) 	/* ���⮢� 䠩� */
	HSCLI_EOF
/* ������� ���筨� ������
 * �������: = 0  - �ᯥ�, < 0 - �訡�� */
HSCLI_FUN(hcERR) hcSqlCreateDatasrc(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ���筨�� */
  const char	*driver, 	/* ��� �ࠩ��� */
  const char	*user,	 	/* ��� ���짮��⥫� */
  const char	*pswd) 		/* ��஫� */
	HSCLI_EOF
/* ����� ������ � ���筨�� ������
 * �������: = 0  - �ᯥ�, < 0 - �訡�� */
HSCLI_FUN(hcERR) hcSqlAlterDatasrcLogin(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ���筨�� */
  const char	*user,	 	/* ��� ���짮��⥫� */
  const char	*pswd) 		/* ��஫� */
	HSCLI_EOF


/* ������� ������ */
HSCLI_FUN(hcERR) hcSqlAllocStmt(
  hcHDB		db,		/* ���������� */
  hcHSTMT 	*p)		/* ���� ��� ����� ������ */
  	HSCLI_EOF
/* ������� ������ */
HSCLI_FUN(hcERR) hcSqlFreeStmt(
  hcHSTMT	h)		/* �����䨪��� ������ */
  	HSCLI_EOF
/* ��������� ��ࠬ��஢ ������ */
HSCLI_FUN(hcERR) hcSqlSetStmtAttr(
  hcHSTMT	h,		/* �����䨪��� ������ */
  unsigned	option,		/* ����� */
  void		*pValue,	/* ���祭�� (int/long) ��� ���� ���祭�� */
  unsigned	size)		/* ������ ���� ��� 0, �᫨ ��।����� int/long */
  	HSCLI_EOF
/* ��࠭᫨஢��� � �믮����� SQL-�ਯ� */
HSCLI_FUN(hcERR) hcSqlExecDirect(
  hcHSTMT	h,		/* �����䨪��� ������ */
  const char 	*text)		/* ����� SQL-�ਯ� */
  	HSCLI_EOF
/* ��࠭᫨஢��� � �믮����� SQL-�ਯ� */
HSCLI_FUN(hcERR) hcSqlExecDirectAsync(
  hcHSTMT	h,		/* �����䨪��� ������ */
  const char 	*text)		/* ����� SQL-�ਯ� */
  	HSCLI_EOF
/* ������� १���� �믮������ ����� */
HSCLI_FUN(hcERR) hcSqlExecDirectQuery(
  hcHSTMT	h)		/* �����䨪��� ������ */
  	HSCLI_EOF
/* ������� ������⢮ ������� १���� */
HSCLI_FUN(hcERR) hcSqlNumResultCols(
  hcHSTMT	h,		/* �����䨪��� ������ */
  int		*pCol)		/* ���� ��� ������⢠ ������� */
  	HSCLI_EOF
/* ������� ������⢮ ��ப १���� */
HSCLI_FUN(hcERR) hcSqlRowCount(
  hcHSTMT	h,		/* �����䨪��� ������ */
  hcRECNO	*pCnt)		/* ���� ��� ������⢠ ��ப */
  	HSCLI_EOF

/* ��� १���� � ������ */
#define	HSCLI_RES_NONE		-1	/* ������� ��� */
#define	HSCLI_RES_RECORD	0	/* ������� ᮤ�ন� ᯨ᮪ ����ᥩ */
#define	HSCLI_RES_JOIN		3	/* ������� ᮤ�ন� १���� ᫨ﭨ� ⠡��� */
#define	HSCLI_RES_SORTED	4	/* ������� ᮤ�ন� �����஢���� ᯨ᮪ ����ᥩ */
#define	HSCLI_RES_GROUP		5	/* ������� ᮤ�ন� १����� ����樨 ��㯯�஢�� */
#define	HSCLI_RES_SORTJOIN	6	/* ������� ᮤ�ন� �����஢����� ᫨ﭨ� ⠡��� */
/* ������ ⨯� ������ � �� */
#define HSCLI_ET_CHAR		0	/* ���ᨢ ᨬ����� ������ �� ����� �������� */
#define HSCLI_ET_ARRA		1	/* ���ᨢ ���⮢ �������� ����� */
#define HSCLI_ET_BYTE		2	/* ������� - unsigned char (���⪮� 楫��) */
#define HSCLI_ET_INTR		3	/* ������� - signed short */
#define HSCLI_ET_WORD		4	/* ������� - unsigned short */
#define HSCLI_ET_DATE		5	/* ���    - unsigned short */
#define HSCLI_ET_NMBR		6	/* �����   - 3-� ���⮢�� 楫�� ��� ����� */
#define HSCLI_ET_LONG		7	/* ������� - long int */
#define HSCLI_ET_DWRD		8	/* ������� - unsigned long int */
#define HSCLI_ET_FLOA		9	/* ������� - float  */
#define HSCLI_ET_CURR		10	/* ���죨 (double)  */
#define HSCLI_ET_DFLT		11	/* ������� - double */
#define HSCLI_ET_QINT		12	/* ������� - signed __int64 */
#define HSCLI_ET_QWRD		13	/* ������� - unsigned __int64 */
/* ���祢� ���� � �� */
#define HSCLI_EK_NOTKEY		0	/* ������� �� ����     */
#define HSCLI_EK_COMMON		1	/* ����� ����        */
#define HSCLI_EK_UNIQUE		2	/* �������� ����     */
#define HSCLI_EK_SURRGT		3	/* ���ண��� ����    */
/* ������� ���ଠ�� �� ������ */
#define HSCLI_STMT_SAB_TYPE     102 	/* ⨯ १���� � SAB (int) */
#define HSCLI_STMT_SAB_HNDCNT	103	/* ������⢮ ht-��ࠡ��稪�� (int) */
#define HSCLI_STMT_SAB_HANDLES	104	/* ht-��ࠡ��稪� (int * i) */
#define HSCLI_STMT_ALS_CNT	105	/* ������⢮ alias-�� (int) */
typedef struct hcSqlAliasInfoT
{	int	hthandle;
	char	tname[32];
	char	aname[32];
} hcSqlAliasInfoT;
#define HSCLI_STMT_ALS_INFO	106	/* ���ଠ�� �� ������ (aliasinfo * i) */
typedef struct hcSqlDstInfoT
{	int		aliasno;
	int		fieldno;
	int		type;
	unsigned	len;
	unsigned	off;
	char		coder[32];
	char		fname[32];
	int		func;
	char		asname[32];
	int		key;
	int		resno;
} hcSqlDstInfoT;
#define HSCLI_STMT_DST_INFO	107	/* ���ଠ�� �� ������� १���� dst (dstinfo * i) */
#define HSCLI_STMT_RC_TYPE	109	/* ��� retcode (int) */
#define HSCLI_STMT_RC_SIZE	110	/* ����� retcode (int) */
#define HSCLI_STMT_RC_BODY	111	/* ���祭�� retcode (char[], long, double) */
#define	HSCLI_STMT_CURSNO	140	/* ����� ����� � HTSQL-�ࢥ� (int) */
HSCLI_FUN(hcERR) hcSqlGetStmtAttr(
  hcHSTMT	h,		/* �����䨪��� ������ */
  unsigned	option,		/* ����� */
  int		pos,		/* ������ */
  void		*pValue,	/* ���� ��� ���祭�� */
  unsigned	size,		/* � ��� ࠧ��� */
  unsigned	*cnt)		/* ᪮�쪮 ���⮢ ����ᠫ� � ���� */
  	HSCLI_EOF
/* ������ १����� ��� �⥭��. ������� �����, �⮡࠭��
 * �����஬ select � ��⮬ �� ��ࠦ����, ����� � ��� ������. */
HSCLI_FUN(hcERR) hcSqlOpenResults(
  hcHSTMT	h,		/* ������ � १���⠬� */
  unsigned 	*pRecSize) 	/* � �������� ࠧ��� ����� */
  	HSCLI_EOF
/* �⥭�� १���⮢ � 㪠������ ����樨 */
HSCLI_FUN(hcERR) hcSqlReadResults(
  hcHSTMT	h,		/* ������ � १���⠬� */
  hcRECNO	gStart,		/* � ����� ����� ��稭��� ���� */
  void		*pBuf,		/* ���� ���� ��� १���⮢ */
  unsigned 	wBufSize, 	/* ������ ���� �⮣� ���� */
  unsigned	*cnt)    	/* ����쪮 ���⠫� */
  	HSCLI_EOF
/* ������� ����� � १���⠬ */
HSCLI_FUN(hcERR) hcSqlCloseResults(
  hcHSTMT	h)		/* ������ � १���⠬� */
  	HSCLI_EOF

/***************************************************************
	"��࠭��" �㭪樨
 ***************************************************************/

/* �������� ������� � १����� ���᪠
 * ����� � ��室�� १���⠬ ������ ���� ����� */
HSCLI_FUN(hcERR) hcSqlIncludeResultsItem(
  hcHSTMT	h,		/* ������ � १���⠬� */
  hcRECNO	gRecNo,		/* �㤠 ��⠢���� (�� 0) */
				/* RES_RECORD - 䨧.����� ����� */
  const void	*pNewItem,	/* ���� ������� १����: */
				/* RES_SORTED - ��ࠡ��稪 ����� */
				/* RES_JOIN - ��㯯� ��ࠡ��稪�� ����ᥩ ��� ⠡��� ᫨ﭨ� */
				/* RES_VALUE, RES_HISTO, RES_GROUP - ⥫� ������� */
  unsigned 	wLen)		/* ����� ������ ������� (� �����) */
	HSCLI_EOF
/* �᪫���� ������� �� १���⮢ ���᪠
 * ����� � ��室�� १���⠬ ������ ���� ����� */
HSCLI_FUN(hcERR) hcSqlExcludeResultsItem(
  hcHSTMT	h,		/* ������ � १���⠬� */
  hcRECNO	gRecNo)		/* �� 㤠���� (�� 0) */
				/* RES_RECORD - 䨧.����� ����� */
	HSCLI_EOF
/* �������� ������� � १����� ���᪠
 * ����� � ��室�� १���⠬ ������ ���� ����� */
HSCLI_FUN(hcERR) hcSqlReplaceResultsItem(
  hcHSTMT	h,		/* ������ � १���⠬� */
  hcRECNO	gRecNo,		/* �� ������ (�� 0) */
				/* RES_RECORD - 䨧.����� ����� */
  const	void	*pNewItem,	/* ���� ������� १����: */
				/* RES_SORTED - ��ࠡ��稪 ����� */
				/* RES_JOIN - ��㯯� ��ࠡ��稪�� ����ᥩ ��� ⠡��� ᫨ﭨ� */
				/* RES_VALUE, RES_HISTO, RES_GROUP - ⥫� ������� */
  unsigned 	wLen)		/* ����� ������ ������� (� �����) */
	HSCLI_EOF
/* ����� ������� १���� ���᪠ - ��ࠡ��稪 �����(��)
 * ����� � ��室�� १���⠬ ������ ���� �����
 * �����⨬ ��� १���⮢ RES_RECORD, RES_SORTED � RES_JOIN */
/* ������ �㭪樨 htGetResultsItem */
HSCLI_FUN(hcERR) hcSqlGetResultsItem(
  hcHSTMT	h,		/* ������ � १���⠬� */
  hcRECNO	gRecNo,		/* �� ���� (�� 0) */
				/* RES_RECORD - 䨧.����� ����� */
  void		*pItem,		/* ����� ������� ��।������ ⨯�� १����: */
				/* RES_SORTED - sizeof(RHANDLE) */
				/* RES_JOIN - sizeof(RHANDLE) * �᫮_⠡���_᫨ﭨ� */
  unsigned	bufsz)		/* ����� ���� ��� �⥭�� */
	HSCLI_EOF
/* "�ᢥ����" १����� ���᪠ (�����஢���� �����), �ਢ��� */
/* �� � ᮮ⢥��⢨� � ⥪�騬 ���ﭨ�� ⠡����. */
/* ����� � ��室�� १���⠬ ������ ���� ������ */
HSCLI_FUN(hcERR) hcSqlStmtTouch(
  hcHSTMT	h)		/* ������ � १���⠬� */
	HSCLI_EOF
/* �������� ��������� ����ᥩ �� ⠡���� */
HSCLI_FUN(hcERR) hcSqlStmtDeleteResults(
  hcHSTMT	h,		/* ������ � १���⠬� */
  long		*cnt)		/* ������⢮ 㤠���� ����ᥩ */
	HSCLI_EOF
/* ����஢�� १���⮢ � ����� */
HSCLI_FUN(hcERR) hcSqlStmtSort(
  hcHSTMT	h,		/* ������ � १���⠬� */
  int		nFldCnt, 	/* ������⢮ ����� ��� ���஢�� */
  hcFLD 	*pFields)	/* ����� ����� ��� ���஢�� */
	HSCLI_EOF
/* ��।����� ���������⢮ ����ᥩ ⠡����, ������� � ���஢�� */
HSCLI_FUN(hcERR) hcSqlStmtUnsort(
  hcHSTMT	h)		/* ������ � १���⠬� */
	HSCLI_EOF

/***************************************************************
	"�祭� ��࠭��" �㭪樨
 ***************************************************************/

/* ���������� ����� */
HSCLI_FUN(hcERR) hcSqlInsertRecord(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ⠡���� */
  unsigned	len,		/* ����� ����� */
  void		*pRecord,	/* ���� ����� */
  hcRECNO	*pRecNo)	/* � �������� ����� ����� */
	HSCLI_EOF
/* ����⭮� ���������� */
HSCLI_FUN(hcERR) hcSqlAddRecords(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*pName,		/* ��⪮� ��� ⠡���� */
  hcRECNO	gRecCount,	/* ������⢮ ����ᥩ */
  unsigned	wRecSize,	/* ������ ����� */
  const void	*pBuf)		/* ���� ���� � ⥫��� ����ᥩ */
	HSCLI_EOF
/* ������� ������ � ����஬ �� ��ࠡ��稪� */
HSCLI_FUN(hcERR) hcSqlReadRecordByHandle(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ⠡���� */
  hcRHANDLE	hRecord,	/* ��ࠡ��稪 ����� */
  void		*pRecord,	/* ���� ���� ��� ����� � ����஬ */
  unsigned	bufsz)		/* ������ ���� */
	HSCLI_EOF
/* ������� ��ࠡ��稪 ����� �� 䨧��᪮�� ������ */
HSCLI_FUN(hcERR) hcSqlHandleFromRecNo(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  const char	*name, 		/* ��� ⠡���� */
  hcRECNO	gRecNo,		/* ����� ����� */
  hcRHANDLE	*record)
	HSCLI_EOF
/* ����䨪��� ����� */
#define HSCLI_OP_POSITION	1	/* ����樮��஢���� � �⥭�� */
#define HSCLI_OP_REFRESH	2	/* �⥭�� ᢥ��� ����� */
#define HSCLI_OP_UPDATE		3	/* ����䨪��� */
#define HSCLI_OP_DELETE		4	/* �������� */
#define HSCLI_OP_INSERT		5	/* ��⠢�� */
#define HSCLI_LOCK_BEFORE	0x0001	/* ��墠� ����� ��। ����樥� */
#define HSCLI_UNLOCK_AFTER	0x0002	/* �᢮�������� ����� ��᫥ ����樨 */
#define HSCLI_LOCK_INTIME	0x0004	/* ��墠� ����� �� �६� ����樨 */
#define HSCLI_RECORD_MAIN	0x0008	/* ��墠� ⮫쪮 ������� ����� */
#define HSCLI_TWISE_ERROR	0x0010	/* ������� ��墠� - �訡�� */
HSCLI_FUN(hcERR) hcSqlStmtEdit(
  hcHSTMT	h,		/* ������ � १���⠬� */
  const char 	*pTab,		/* ��� �ᥢ������ ⠡���� � ����� ��� 0 */
  hcRECNO	row,		/* ����� ��ப� � ����� (��⠥��� �� 0) */
  int		op,		/* ������: HSSQL_OP_??? */
  int		lock,		/* ��墠�, ��⮢�� ��᪠, HS_LOCK/HS_UNLOCK */
  void		*buf,		/* ���� ���� ����� */
  unsigned 	sz,             /* ������ ���� */
  hcRECNO	*recno)
	HSCLI_EOF
/* ��⠢��� � ����� ��᪮�쪮 ����ᥩ � 㪠����묨 ����ࠬ� */
HSCLI_FUN(hcERR) hcSqlFormRecordsSet(
  hcHSTMT	h,		/* ������ � १���⠬� */
  const char	*pName,		/* ���⪮� ��� ⠡����, �� ���ன ���� ᮧ���� �����, ��� NULL */
  hcRECNO	gCnt,		/* ������⢮ ��⠢�塞�� ����ᥩ */
  const hcRECNO	*pRecordNo)	/* ���� ���ᨢ� � ����ࠬ� ����ᥩ */
	HSCLI_EOF
/* �⥭�� ������ ᮮ�饭�� */
HSCLI_FUN(hcERR) hcSqlConnReadMsg(
  hcHDB		hdb,		/* �����䨪��� ᮥ������� */
  void		*buf,		/* ���� ���� ����� */
  unsigned 	sz,             /* ������ ���� */
  unsigned	*cnt)    	/* ����쪮 ���⠫� */
	HSCLI_EOF

/***************************************************************
	����७��� �।�⠢����� ������
 ***************************************************************/
/* �������� ���� */
/* 0 - ���ࠢ��쭠� ��� */
HSCLI_FUN(unsigned short) hcSqlPackDate(
  unsigned	day,		/* ���� ����� (1-31) */
  unsigned	month,		/* ����� (1-12) */
  unsigned	year)		/* ��� (1900-2078) */
	HSCLI_EOF
/* ��ᯠ����� ���� */
HSCLI_FUN(hcERR) hcSqlUnpackDate(
  unsigned short htdate,
  unsigned	*day,
  unsigned	*month,
  unsigned	*year)
	HSCLI_EOF
/* �뤥����� ��ப� �� ����, �����頥��� 䫠� ���� ���ଠ樨 */
HSCLI_FUN(int) hcSqlGetChar(
  char		*dst,		/* ���� ��ப� (� \0 ᨬ����� � ����) */
  unsigned	dstlen,		/* ����� ���� ��ப� */
  const unsigned char *field,	/* ���� */
  unsigned	fldlen)		/* ����� ���� */
	HSCLI_EOF
/* ��।������ ����� ��ப� � ���� */
HSCLI_FUN(unsigned) hcSqlGetCharLen(
  const unsigned char *field,	/* ���� */
  unsigned	fldlen)		/* ����� ���� */
	HSCLI_EOF
/* ����ᥭ�� ��ப� � ����, �����頥��� 䫠� ���� ���ଠ樨 */
HSCLI_FUN(int) hcSqlSetChar(
  unsigned char *field,		/* ���� */
  unsigned	fldlen,		/* ����� ���� */
  const char	*src)		/* ��室��� ��ப� */
	HSCLI_EOF
/* ����ᥭ�� null-���祭�� */
HSCLI_FUN(hcERR) hcSqlSetNull(
  unsigned char *field,		/* ���� */
  int		type,		/* ��� ���� (HSCLI_ET_???) */
  unsigned	typlen)		/* ����� ���� ��६����� ����� */
	HSCLI_EOF
/* �஢�ઠ null-���祭�� */
HSCLI_FUN(hcERR) hcSqlIsNull(
  const unsigned char *field,	/* ���� */
  int		type,		/* ��� ���� (HSCLI_ET_???) */
  unsigned	typlen)		/* ����� ���� ��६����� ����� */
	HSCLI_EOF
  
HSCLI_FUN(hcERR) hscliProcStart(void);
HSCLI_FUN(hcERR) hscliProcExit(void);
HSCLI_FUN(hcERR) hscliThrdStart(void);
HSCLI_FUN(hcERR) hscliThrdExit(void);

#endif
