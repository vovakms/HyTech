/***************************************************************

	Интерфейс к динамической библиотеке HSCLI.DLL

	Клиент (1.1.6.16)

 История:
 ========
 22.10.04	Тестовый вариант

 ***************************************************************/
#ifndef HSCLI_H_INCLUDED
#define HSCLI_H_INCLUDED

/* Для построения фиктивной DLL*/
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

/* Функции, экспортируемые из DLL */
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
#  define HSCLI_FUN(type) HSCLI_PFX type __declspec(dllexport) __stdcall
#  define HSCLI_CBK __stdcall
# else
#  define HSCLI_FUN(type) HSCLI_PFX type  __declspec(dllimport) __stdcall
#  define HSCLI_CBK __stdcall
# endif
#else
# error !os
#endif


/* Ошибки локальной части */
#define	SQL_RTL_LCL_REMOTE		-20001	/* Ошибка связи */
#define	SQL_RTL_LCL_USER_BREAK		-20002	/* Обработка прервана пользователем */
#define	SQL_RTL_LCL_NO_INIT		-20003	/* Не инициализировано */
#define	SQL_RTL_LCL_GENERAL_ERROR	-20004	/* Другая ошибка */
#define SQL_RTL_LCL_BUSY		-20005	/* Предыдущая операция не завершена */
#define	SQL_RTL_LCL_NO_MEMORY		-20006	/* Мало памяти */
#define SQL_RTL_LCL_TOO_MANY_SESSIONS	-20007	/* Много сессий */
#define	SQL_RTL_LCL_INV_ARG		-20008	/* Неправильный аргумент */
#define SQL_RTL_LCL_TOO_OLD_SERVER	-20009	/* Старый сервер */

/***************************************************************
	Типы данных и константы
 ***************************************************************/
/* Идентификатор оператора */
typedef int hcHSTMT;
/* Идентификатор соединения */
typedef int hcHDB;
/* Номер поля */
typedef int hcFLD;
/* Номер записи в таблице или результате */
typedef long hcRECNO;
/* Обработчик записи */
typedef long hcRHANDLE;
/* Код ошибки */
//#ifndef HSCLI_DLL
typedef int hcERR;
//#endif

/* Функция обработки текстовых сообщений сервера */
typedef void HSCLI_CBK hcSqlCbkSrvMsgT(hcHDB conn, int is_err);
typedef void HSCLI_CBK hcSqlCbkStmtSrvMsgT(hcHDB conn, hcHSTMT stmt, int is_err);
/* Функция обработки Usersend */
typedef void HSCLI_CBK hcSqlCbkSrvUserSendT(hcHDB conn, int usertype);
typedef void HSCLI_CBK hcSqlCbkStmtSrvUserSendT(hcHDB conn, hcHSTMT stmt, int usertype);

/* Параметры инициализации */
typedef struct hcSqlParmT
{	unsigned	size;		/* Размер структуры */
} hcSqlParmT;

/***************************************************************
	Функции
 ***************************************************************/
/* Инициализировать клиентскую часть */
HSCLI_FUN(hcERR) hcSqlInit(
  hcSqlParmT	*arg)		/* Аргументы инициализации */
  	HSCLI_EOF
/* Завершить работу */
HSCLI_FUN(hcERR) hcSqlDone(void)
  	HSCLI_EOF
/* Проверить завершение инициализации */
HSCLI_FUN(hcERR) hcSqlCheckInit(void)
	HSCLI_EOF

/* Создать соединение */
HSCLI_FUN(hcERR) hcSqlAllocConnect(
  hcHDB		*pdb)		/* Соединение */
  	HSCLI_EOF
/* Освободить соединение */
HSCLI_FUN(hcERR) hcSqlFreeConnect(
  hcHDB		hdb)		/* Соединение */
  	HSCLI_EOF
/* Установить связь с сервером БД */
HSCLI_FUN(hcERR) hcSqlConnect(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*server,
  const char	*user,
  const char	*password)
  	HSCLI_EOF
/* Разорвать связь с сервером БД */
HSCLI_FUN(hcERR) hcSqlDisconnect(
  hcHDB		hdb)		/* Идентификатор соединения */
  	HSCLI_EOF
/* Получить информацию об соединении */
#define HSCLI_CONN_SRV_PATH	101	/* строка соединения (char[]) */
#define HSCLI_CONN_SRV_VERS	102	/* Версия сервера (double) */
#define HSCLI_CONN_SRV_VERS2	103	/* Версия сервера (char[]) */
#define HSCLI_CONN_USER_INFO	151	/* Информация пользователя (long) */
#define HSCLI_CONN_LCLADDR	152	/* Адрес (клиента) (char[]) */
#define HSCLI_CONN_RMTADDR	153	/* Адрес (сервера) (char[]) */
HSCLI_FUN(hcERR) hcSqlGetConnectAttr(
  hcHDB		h,		/* Идентификатор соединения */
  unsigned	option,		/* Режим */
  int		pos,		/* Позиция */
  void		*pValue,	/* Буфер для значения */
  unsigned	size,		/* и его размер */
  unsigned	*cnt)		/* сколько байтов записали в буфер */
  	HSCLI_EOF
#define HSCLI_ATTR_FLD_VERBOSE		1001	/* [conn/stmt] Расширенная информация о полях (int) */
#define HSCLI_ATTR_CONN_USER_INFO	1002	/* [conn/stmt] Информация пользователя (long) */
#define	HSCLI_ATTR_CBK_SRVMSG		1100	/* [conn] Функция обработки сообщений сервера (hcSqlCbkSrvMsgT*) */
#define	HSCLI_ATTR_CBK_SRVUSERSEND	1101	/* [conn] Функция обработки пользовательских сообщений сервера (hcSqlCbkSrvUserSendT*) */
#define	HSCLI_ATTR_CBK_STMT_SRVMSG	1102	/* [stmt] Функция обработки сообщений сервера (hcSqlCbkStmtSrvMsgT*) */
#define	HSCLI_ATTR_CBK_STMT_SRVUSERSEND	1103	/* [stmt] Функция обработки пользовательских сообщений сервера (hcSqlCbkStmtSrvUserSendT*) */
/* Изменение параметров соединения */
HSCLI_FUN(hcERR) hcSqlSetConnectAttr(
  hcHDB		h,		/* Идентификатор соединения */
  unsigned	option,		/* Режим */
  void		*pValue,	/* Значение (int/long) или буфер значения */
  unsigned	size)		/* Размер значения в байтах или 0, если передаётся int/long */
  	HSCLI_EOF
/* Сменить пароль пользователя
 * Результат: = 0  - успех, < 0 - ошибка */
HSCLI_FUN(hcERR) hcSqlAlterPassword(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя пользователя */
  const char	*oldpswd, 	/* Старый пароль */
  const char	*newpswd) 	/* Новый пароль */
	HSCLI_EOF

/* Создать пользователя
 * Результат: = 0  - успех, < 0 - ошибка */
HSCLI_FUN(hcERR) hcSqlCreateUser(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя пользователя */
  const char	*pswd, 		/* Пароль */
  const char	*profile, 	/* Профиль */
  const char	*startup) 	/* Стартовый файл */
	HSCLI_EOF
/* Создать Источник данных
 * Результат: = 0  - успех, < 0 - ошибка */
HSCLI_FUN(hcERR) hcSqlCreateDatasrc(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя источника */
  const char	*driver, 	/* Имя драйвера */
  const char	*user,	 	/* имя пользователя */
  const char	*pswd) 		/* Пароль */
	HSCLI_EOF
/* Смена логина у источника данных
 * Результат: = 0  - успех, < 0 - ошибка */
HSCLI_FUN(hcERR) hcSqlAlterDatasrcLogin(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя источника */
  const char	*user,	 	/* имя пользователя */
  const char	*pswd) 		/* Пароль */
	HSCLI_EOF


/* Создать оператор */
HSCLI_FUN(hcERR) hcSqlAllocStmt(
  hcHDB		db,		/* Соединение */
  hcHSTMT 	*p)		/* Место для номера оператора */
  	HSCLI_EOF
/* Закрыть оператор */
HSCLI_FUN(hcERR) hcSqlFreeStmt(
  hcHSTMT	h)		/* Идентификатор оператора */
  	HSCLI_EOF
/* Изменение параметров оператора */
HSCLI_FUN(hcERR) hcSqlSetStmtAttr(
  hcHSTMT	h,		/* Идентификатор оператора */
  unsigned	option,		/* Режим */
  void		*pValue,	/* Значение (int/long) или буфер значения */
  unsigned	size)		/* Размер буфера или 0, если передаётся int/long */
  	HSCLI_EOF
/* Странслировать и выполнить SQL-скрипт */
HSCLI_FUN(hcERR) hcSqlExecDirect(
  hcHSTMT	h,		/* Идентификатор оператора */
  const char 	*text)		/* Текст SQL-скрипта */
  	HSCLI_EOF
/* Странслировать и выполнить SQL-скрипт */
HSCLI_FUN(hcERR) hcSqlExecDirectAsync(
  hcHSTMT	h,		/* Идентификатор оператора */
  const char 	*text)		/* Текст SQL-скрипта */
  	HSCLI_EOF
/* Получить результат выполнения запроса */
HSCLI_FUN(hcERR) hcSqlExecDirectQuery(
  hcHSTMT	h)		/* Идентификатор оператора */
  	HSCLI_EOF
/* Получить количество колонок результата */
HSCLI_FUN(hcERR) hcSqlNumResultCols(
  hcHSTMT	h,		/* Идентификатор оператора */
  int		*pCol)		/* Место для количества колонок */
  	HSCLI_EOF
/* Получить количество строк результата */
HSCLI_FUN(hcERR) hcSqlRowCount(
  hcHSTMT	h,		/* Идентификатор оператора */
  hcRECNO	*pCnt)		/* Место для количества строк */
  	HSCLI_EOF

/* Тип результата в операторе */
#define	HSCLI_RES_NONE		-1	/* Результата нет */
#define	HSCLI_RES_RECORD	0	/* Результат содержит список записей */
#define	HSCLI_RES_JOIN		3	/* Результат содержит результат слияния таблиц */
#define	HSCLI_RES_SORTED	4	/* Результат содержит отсортированный список записей */
#define	HSCLI_RES_GROUP		5	/* Результат содержит результаты операции группировки */
#define	HSCLI_RES_SORTJOIN	6	/* Результат содержит отсортированное слияние таблиц */
/* Базовые типы данных в БД */
#define HSCLI_ET_CHAR		0	/* Массив символов длиной не более заданной */
#define HSCLI_ET_ARRA		1	/* Массив байтов заданной длины */
#define HSCLI_ET_BYTE		2	/* Элемент - unsigned char (короткое целое) */
#define HSCLI_ET_INTR		3	/* Элемент - signed short */
#define HSCLI_ET_WORD		4	/* Элемент - unsigned short */
#define HSCLI_ET_DATE		5	/* Дата    - unsigned short */
#define HSCLI_ET_NMBR		6	/* Номер   - 3-х байтовое целое без знака */
#define HSCLI_ET_LONG		7	/* Элемент - long int */
#define HSCLI_ET_DWRD		8	/* Элемент - unsigned long int */
#define HSCLI_ET_FLOA		9	/* Элемент - float  */
#define HSCLI_ET_CURR		10	/* Деньги (double)  */
#define HSCLI_ET_DFLT		11	/* Элемент - double */
#define HSCLI_ET_QINT		12	/* Элемент - signed __int64 */
#define HSCLI_ET_QWRD		13	/* Элемент - unsigned __int64 */
/* Ключевые поля в БД */
#define HSCLI_EK_NOTKEY		0	/* Элемент не ключ     */
#define HSCLI_EK_COMMON		1	/* Обычный ключ        */
#define HSCLI_EK_UNIQUE		2	/* Уникальный ключ     */
#define HSCLI_EK_SURRGT		3	/* Суррогатный ключ    */
/* Получить информацию об операторе */
#define HSCLI_STMT_SAB_TYPE     102 	/* тип результата в SAB (int) */
#define HSCLI_STMT_SAB_HNDCNT	103	/* количество ht-обработчиков (int) */
#define HSCLI_STMT_SAB_HANDLES	104	/* ht-обработчики (int * i) */
#define HSCLI_STMT_ALS_CNT	105	/* количество alias-ов (int) */
typedef struct hcSqlAliasInfoT
{	int	hthandle;
	char	tname[32];
	char	aname[32];
} hcSqlAliasInfoT;
#define HSCLI_STMT_ALS_INFO	106	/* информация об алиасах (aliasinfo * i) */
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
#define HSCLI_STMT_DST_INFO	107	/* Информация об колонке результата dst (dstinfo * i) */
#define HSCLI_STMT_RC_TYPE	109	/* Тип retcode (int) */
#define HSCLI_STMT_RC_SIZE	110	/* Длина retcode (int) */
#define HSCLI_STMT_RC_BODY	111	/* Значение retcode (char[], long, double) */
#define	HSCLI_STMT_CURSNO	140	/* Номер курсора в HTSQL-сервере (int) */
HSCLI_FUN(hcERR) hcSqlGetStmtAttr(
  hcHSTMT	h,		/* Идентификатор оператора */
  unsigned	option,		/* Режим */
  int		pos,		/* Позиция */
  void		*pValue,	/* Буфер для значения */
  unsigned	size,		/* и его размер */
  unsigned	*cnt)		/* сколько байтов записали в буфер */
  	HSCLI_EOF
/* Открыть результаты для чтения. Читаются данные, отобранные
 * оператором select с учетом тех выражений, которые в нем заданы. */
HSCLI_FUN(hcERR) hcSqlOpenResults(
  hcHSTMT	h,		/* Оператор с результатами */
  unsigned 	*pRecSize) 	/* Сюда запишется размер записи */
  	HSCLI_EOF
/* Чтение результатов с указанной позиции */
HSCLI_FUN(hcERR) hcSqlReadResults(
  hcHSTMT	h,		/* Оператор с результатами */
  hcRECNO	gStart,		/* С какой записи начинаем читать */
  void		*pBuf,		/* Адрес буфера для результатов */
  unsigned 	wBufSize, 	/* Размер буфера этого буфера */
  unsigned	*cnt)    	/* Сколько прочитали */
  	HSCLI_EOF
/* Закрыть доступ к результатам */
HSCLI_FUN(hcERR) hcSqlCloseResults(
  hcHSTMT	h)		/* Оператор с результатами */
  	HSCLI_EOF

/***************************************************************
	"Странные" функции
 ***************************************************************/

/* Добавить элемент в результаты поиска
 * Доступ к исходным результатам должен быть открыт */
HSCLI_FUN(hcERR) hcSqlIncludeResultsItem(
  hcHSTMT	h,		/* Оператор с результатами */
  hcRECNO	gRecNo,		/* Куда вставлять (от 0) */
				/* RES_RECORD - физ.номер записи */
  const void	*pNewItem,	/* Новый элемент результата: */
				/* RES_SORTED - обработчик записи */
				/* RES_JOIN - группа обработчиков записей для таблиц слияния */
				/* RES_VALUE, RES_HISTO, RES_GROUP - тело элемента */
  unsigned 	wLen)		/* Длина нового элемента (в байтах) */
	HSCLI_EOF
/* Исключить элемент из результатов поиска
 * Доступ к исходным результатам должен быть открыт */
HSCLI_FUN(hcERR) hcSqlExcludeResultsItem(
  hcHSTMT	h,		/* Оператор с результатами */
  hcRECNO	gRecNo)		/* Что удалять (от 0) */
				/* RES_RECORD - физ.номер записи */
	HSCLI_EOF
/* Заменить элемент в результатах поиска
 * Доступ к исходным результатам должен быть открыт */
HSCLI_FUN(hcERR) hcSqlReplaceResultsItem(
  hcHSTMT	h,		/* Оператор с результатами */
  hcRECNO	gRecNo,		/* Что менять (от 0) */
				/* RES_RECORD - физ.номер записи */
  const	void	*pNewItem,	/* Новый элемент результата: */
				/* RES_SORTED - обработчик записи */
				/* RES_JOIN - группа обработчиков записей для таблиц слияния */
				/* RES_VALUE, RES_HISTO, RES_GROUP - тело элемента */
  unsigned 	wLen)		/* Длина нового элемента (в байтах) */
	HSCLI_EOF
/* Считать элемент результата поиска - обработчик записи(ей)
 * Доступ к исходным результатам должен быть открыт
 * Допустим для результатов RES_RECORD, RES_SORTED и RES_JOIN */
/* Аналог функции htGetResultsItem */
HSCLI_FUN(hcERR) hcSqlGetResultsItem(
  hcHSTMT	h,		/* Оператор с результатами */
  hcRECNO	gRecNo,		/* Что читать (от 0) */
				/* RES_RECORD - физ.номер записи */
  void		*pItem,		/* Длина элемента определяется типом результата: */
				/* RES_SORTED - sizeof(RHANDLE) */
				/* RES_JOIN - sizeof(RHANDLE) * число_таблиц_слияния */
  unsigned	bufsz)		/* Длина буфера для чтения */
	HSCLI_EOF
/* "Освежить" результаты поиска (несортированные записи), привести */
/* их в соответствие с текущим состоянием таблицы. */
/* Доступ к исходным результатам должен быть закрыт */
HSCLI_FUN(hcERR) hcSqlStmtTouch(
  hcHSTMT	h)		/* Оператор с результатами */
	HSCLI_EOF
/* Удаление найденных записей из таблицы */
HSCLI_FUN(hcERR) hcSqlStmtDeleteResults(
  hcHSTMT	h,		/* Оператор с результатами */
  long		*cnt)		/* Количество удалённых записей */
	HSCLI_EOF
/* Сортировка результатов в курсоре */
HSCLI_FUN(hcERR) hcSqlStmtSort(
  hcHSTMT	h,		/* Оператор с результатами */
  int		nFldCnt, 	/* Количество полей для сортировки */
  hcFLD 	*pFields)	/* Номера полей для сортировки */
	HSCLI_EOF
/* Определить подмножество записей таблицы, попавших в сортировку */
HSCLI_FUN(hcERR) hcSqlStmtUnsort(
  hcHSTMT	h)		/* Оператор с результатами */
	HSCLI_EOF

/***************************************************************
	"Очень странные" функции
 ***************************************************************/

/* Добавление записи */
HSCLI_FUN(hcERR) hcSqlInsertRecord(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя таблицы */
  unsigned	len,		/* Длина записи */
  void		*pRecord,	/* Тело записи */
  hcRECNO	*pRecNo)	/* Сюда запишется номер записи */
	HSCLI_EOF
/* Пакетное добавление */
HSCLI_FUN(hcERR) hcSqlAddRecords(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*pName,		/* Краткое имя таблицы */
  hcRECNO	gRecCount,	/* Количество записей */
  unsigned	wRecSize,	/* Размер записи */
  const void	*pBuf)		/* Адрес буфера с телами записей */
	HSCLI_EOF
/* Получить запись с номером по обработчику */
HSCLI_FUN(hcERR) hcSqlReadRecordByHandle(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя таблицы */
  hcRHANDLE	hRecord,	/* Обработчик записи */
  void		*pRecord,	/* Адрес буфера для записи с номером */
  unsigned	bufsz)		/* Размер буфера */
	HSCLI_EOF
/* Получить обработчик записи по физическому номеру */
HSCLI_FUN(hcERR) hcSqlHandleFromRecNo(
  hcHDB		hdb,		/* Идентификатор соединения */
  const char	*name, 		/* Имя таблицы */
  hcRECNO	gRecNo,		/* Номер записи */
  hcRHANDLE	*record)
	HSCLI_EOF
/* Модификация курсора */
#define HSCLI_OP_POSITION	1	/* Позиционирование и чтение */
#define HSCLI_OP_REFRESH	2	/* Чтение свежей записи */
#define HSCLI_OP_UPDATE		3	/* Модификация */
#define HSCLI_OP_DELETE		4	/* Удаление */
#define HSCLI_OP_INSERT		5	/* Вставка */
#define HSCLI_LOCK_BEFORE	0x0001	/* Захват записи перед операцией */
#define HSCLI_UNLOCK_AFTER	0x0002	/* Освобождение записи после операции */
#define HSCLI_LOCK_INTIME	0x0004	/* Захват записи во время операции */
#define HSCLI_RECORD_MAIN	0x0008	/* Захват только главной записи */
#define HSCLI_TWISE_ERROR	0x0010	/* Двойной захват - ошибка */
HSCLI_FUN(hcERR) hcSqlStmtEdit(
  hcHSTMT	h,		/* Оператор с результатами */
  const char 	*pTab,		/* Имя псевдонима таблицы в запросе или 0 */
  hcRECNO	row,		/* Номер строки в курсоре (считается от 0) */
  int		op,		/* Операция: HSSQL_OP_??? */
  int		lock,		/* Захват, битовая маска, HS_LOCK/HS_UNLOCK */
  void		*buf,		/* Адрес буфер записи */
  unsigned 	sz,             /* Размер буфера */
  hcRECNO	*recno)
	HSCLI_EOF
/* Вставить в курсор несколько записей с указанными номерами */
HSCLI_FUN(hcERR) hcSqlFormRecordsSet(
  hcHSTMT	h,		/* Оператор с результатами */
  const char	*pName,		/* Короткое имя таблицы, по которой надо создать курсор, или NULL */
  hcRECNO	gCnt,		/* Количество вставляемых записей */
  const hcRECNO	*pRecordNo)	/* Адрес массива с номерами записей */
	HSCLI_EOF
/* Чтение данных сообщения */
HSCLI_FUN(hcERR) hcSqlConnReadMsg(
  hcHDB		hdb,		/* Идентификатор соединения */
  void		*buf,		/* Адрес буфер записи */
  unsigned 	sz,             /* Размер буфера */
  unsigned	*cnt)    	/* Сколько прочитали */
	HSCLI_EOF

/***************************************************************
	Внутреннее представление данных
 ***************************************************************/
/* Упаковка даты */
/* 0 - неправильная дата */
HSCLI_FUN(unsigned short) hcSqlPackDate(
  unsigned	day,		/* День месяца (1-31) */
  unsigned	month,		/* Месяц (1-12) */
  unsigned	year)		/* Год (1900-2078) */
	HSCLI_EOF
/* Распаковка даты */
HSCLI_FUN(hcERR) hcSqlUnpackDate(
  unsigned short htdate,
  unsigned	*day,
  unsigned	*month,
  unsigned	*year)
	HSCLI_EOF
/* Выделение строки из поля, возвращается флаг потери информации */
HSCLI_FUN(int) hcSqlGetChar(
  char		*dst,		/* Буфер строки (с \0 символом в конце) */
  unsigned	dstlen,		/* Длина буфера строки */
  const unsigned char *field,	/* Поле */
  unsigned	fldlen)		/* Длина поля */
	HSCLI_EOF
/* Определение длины строки в поле */
HSCLI_FUN(unsigned) hcSqlGetCharLen(
  const unsigned char *field,	/* Поле */
  unsigned	fldlen)		/* Длина поля */
	HSCLI_EOF
/* Занесение строки в поле, возвращается флаг потери информации */
HSCLI_FUN(int) hcSqlSetChar(
  unsigned char *field,		/* Поле */
  unsigned	fldlen,		/* Длина поля */
  const char	*src)		/* Исходная строка */
	HSCLI_EOF
/* Занесение null-значения */
HSCLI_FUN(hcERR) hcSqlSetNull(
  unsigned char *field,		/* Поле */
  int		type,		/* Тип поля (HSCLI_ET_???) */
  unsigned	typlen)		/* Длина поля переменной длины */
	HSCLI_EOF
/* Проверка null-значения */
HSCLI_FUN(hcERR) hcSqlIsNull(
  const unsigned char *field,	/* Поле */
  int		type,		/* Тип поля (HSCLI_ET_???) */
  unsigned	typlen)		/* Длина поля переменной длины */
	HSCLI_EOF
  
HSCLI_FUN(hcERR) hscliProcStart(void);
HSCLI_FUN(hcERR) hscliProcExit(void);
HSCLI_FUN(hcERR) hscliThrdStart(void);
HSCLI_FUN(hcERR) hscliThrdExit(void);

#endif
