CREATE DATABASE TaskWorker
USE TaskWorker;

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('AVAILABLE_IN') and o.name = 'FK_AVAILABL_AVAILABLE_WORKER')
alter table AVAILABLE_IN
   drop constraint FK_AVAILABL_AVAILABLE_WORKER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('AVAILABLE_IN') and o.name = 'FK_AVAILABL_AVAILABLE_AVAILABL')
alter table AVAILABLE_IN
   drop constraint FK_AVAILABL_AVAILABLE_AVAILABL
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('HAS') and o.name = 'FK_HAS_HAS_WORKER')
alter table HAS
   drop constraint FK_HAS_HAS_WORKER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('HAS') and o.name = 'FK_HAS_HAS2_SPECIALI')
alter table HAS
   drop constraint FK_HAS_HAS2_SPECIALI
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('LOCATION') and o.name = 'FK_LOCATION_HAVE2_LOCATION')
alter table LOCATION
   drop constraint FK_LOCATION_HAVE2_LOCATION
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('LOCATION_NAME') and o.name = 'FK_LOCATION_HAVE_LOCATION')
alter table LOCATION_NAME
   drop constraint FK_LOCATION_HAVE_LOCATION
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('REQUEST') and o.name = 'FK_REQUEST_MAKE_CLIENT')
alter table REQUEST
   drop constraint FK_REQUEST_MAKE_CLIENT
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SEARCH_FOR') and o.name = 'FK_SEARCH_F_SEARCH_FO_REQUEST')
alter table SEARCH_FOR
   drop constraint FK_SEARCH_F_SEARCH_FO_REQUEST
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SEARCH_FOR') and o.name = 'FK_SEARCH_F_SEARCH_FO_WORKER')
alter table SEARCH_FOR
   drop constraint FK_SEARCH_F_SEARCH_FO_WORKER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SPECIALITIES') and o.name = 'FK_SPECIALI_REQUIRE_TASK')
alter table SPECIALITIES
   drop constraint FK_SPECIALI_REQUIRE_TASK
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('SUB_TASK') and o.name = 'FK_SUB_TASK_ASSIGNED__TASK')
alter table SUB_TASK
   drop constraint FK_SUB_TASK_ASSIGNED__TASK
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('TASK') and o.name = 'FK_TASK_CONTAINS_REQUEST')
alter table TASK
   drop constraint FK_TASK_CONTAINS_REQUEST
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('WORK_IN') and o.name = 'FK_WORK_IN_WORK_IN_WORKER')
alter table WORK_IN
   drop constraint FK_WORK_IN_WORK_IN_WORKER
go

if exists (select 1
   from sys.sysreferences r join sys.sysobjects o on (o.id = r.constid and o.type = 'F')
   where r.fkeyid = object_id('WORK_IN') and o.name = 'FK_WORK_IN_WORK_IN2_LOCATION')
alter table WORK_IN
   drop constraint FK_WORK_IN_WORK_IN2_LOCATION
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('AVAILABLE_IN')
            and   name  = 'AVAILABLE_IN2_FK'
            and   indid > 0
            and   indid < 255)
   drop index AVAILABLE_IN.AVAILABLE_IN2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('AVAILABLE_IN')
            and   name  = 'AVAILABLE_IN_FK'
            and   indid > 0
            and   indid < 255)
   drop index AVAILABLE_IN.AVAILABLE_IN_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('AVAILABLE_IN')
            and   type = 'U')
   drop table AVAILABLE_IN
go

if exists (select 1
            from  sysobjects
           where  id = object_id('AVAILABLE_SLOT')
            and   type = 'U')
   drop table AVAILABLE_SLOT
go

if exists (select 1
            from  sysobjects
           where  id = object_id('CLIENT')
            and   type = 'U')
   drop table CLIENT
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('HAS')
            and   name  = 'HAS2_FK'
            and   indid > 0
            and   indid < 255)
   drop index HAS.HAS2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('HAS')
            and   name  = 'HAS_FK'
            and   indid > 0
            and   indid < 255)
   drop index HAS.HAS_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('HAS')
            and   type = 'U')
   drop table HAS
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('LOCATION')
            and   name  = 'HAVE2_FK'
            and   indid > 0
            and   indid < 255)
   drop index LOCATION.HAVE2_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('LOCATION')
            and   type = 'U')
   drop table LOCATION
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('LOCATION_NAME')
            and   name  = 'HAVE_FK'
            and   indid > 0
            and   indid < 255)
   drop index LOCATION_NAME.HAVE_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('LOCATION_NAME')
            and   type = 'U')
   drop table LOCATION_NAME
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('REQUEST')
            and   name  = 'MAKE_FK'
            and   indid > 0
            and   indid < 255)
   drop index REQUEST.MAKE_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('REQUEST')
            and   type = 'U')
   drop table REQUEST
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('SEARCH_FOR')
            and   name  = 'SEARCH_FOR2_FK'
            and   indid > 0
            and   indid < 255)
   drop index SEARCH_FOR.SEARCH_FOR2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('SEARCH_FOR')
            and   name  = 'SEARCH_FOR_FK'
            and   indid > 0
            and   indid < 255)
   drop index SEARCH_FOR.SEARCH_FOR_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('SEARCH_FOR')
            and   type = 'U')
   drop table SEARCH_FOR
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('SPECIALITIES')
            and   name  = 'REQUIRE_FK'
            and   indid > 0
            and   indid < 255)
   drop index SPECIALITIES.REQUIRE_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('SPECIALITIES')
            and   type = 'U')
   drop table SPECIALITIES
go

if exists (select 1
            from  sysobjects
           where  id = object_id('SUB_TASK')
            and   type = 'U')
   drop table SUB_TASK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('TASK')
            and   name  = 'CONTAINS_FK'
            and   indid > 0
            and   indid < 255)
   drop index TASK.CONTAINS_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('TASK')
            and   type = 'U')
   drop table TASK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('WORKER')
            and   type = 'U')
   drop table WORKER
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('WORK_IN')
            and   name  = 'WORK_IN2_FK'
            and   indid > 0
            and   indid < 255)
   drop index WORK_IN.WORK_IN2_FK
go

if exists (select 1
            from  sysindexes
           where  id    = object_id('WORK_IN')
            and   name  = 'WORK_IN_FK'
            and   indid > 0
            and   indid < 255)
   drop index WORK_IN.WORK_IN_FK
go

if exists (select 1
            from  sysobjects
           where  id = object_id('WORK_IN')
            and   type = 'U')
   drop table WORK_IN
go

/*==============================================================*/
/* Table: AVAILABLE_IN                                          */
/*==============================================================*/
create table AVAILABLE_IN (
   WORKER_ID            int                  not null,
   SLOT_ID              int                  not null,
   constraint PK_AVAILABLE_IN primary key (WORKER_ID, SLOT_ID)
)
go

/*==============================================================*/
/* Index: AVAILABLE_IN_FK                                       */
/*==============================================================*/




create nonclustered index AVAILABLE_IN_FK on AVAILABLE_IN (WORKER_ID ASC)
go

/*==============================================================*/
/* Index: AVAILABLE_IN2_FK                                      */
/*==============================================================*/




create nonclustered index AVAILABLE_IN2_FK on AVAILABLE_IN (SLOT_ID ASC)
go

/*==============================================================*/
/* Table: AVAILABLE_SLOT                                        */
/*==============================================================*/
create table AVAILABLE_SLOT (
   SLOT_ID              int                  identity,
   START_TIME           datetime             null,
   END_TIME             datetime             null,
   constraint PK_AVAILABLE_SLOT primary key (SLOT_ID)
)
go

/*==============================================================*/
/* Table: CLIENT                                                */
/*==============================================================*/
create table CLIENT (
   CLIENT_ID            int                  identity,
   NAME                 varchar(50)          not null,
   PHONE                varchar(11)          not null,
   ADDRESS              varchar(100)         not null,
   PAYMENT_INFO         varchar(100)         null,
   constraint PK_CLIENT primary key (CLIENT_ID)
)
go

/*==============================================================*/
/* Table: HAS                                                   */
/*==============================================================*/
create table HAS (
   WORKER_ID            int                  not null,
   SPECIALITY_ID        int                  not null,
   constraint PK_HAS primary key (WORKER_ID, SPECIALITY_ID)
)
go

/*==============================================================*/
/* Index: HAS_FK                                                */
/*==============================================================*/




create nonclustered index HAS_FK on HAS (WORKER_ID ASC)
go

/*==============================================================*/
/* Index: HAS2_FK                                               */
/*==============================================================*/




create nonclustered index HAS2_FK on HAS (SPECIALITY_ID ASC)
go

/*==============================================================*/
/* Table: LOCATION                                              */
/*==============================================================*/
create table LOCATION (
   LOCATION_ID          int                  identity,
   LOC_ID               int                  not null,
   constraint PK_LOCATION primary key (LOCATION_ID)
)
go

/*==============================================================*/
/* Index: HAVE2_FK                                              */
/*==============================================================*/




create nonclustered index HAVE2_FK on LOCATION (LOC_ID ASC)
go

/*==============================================================*/
/* Table: LOCATION_NAME                                         */
/*==============================================================*/
create table LOCATION_NAME (
   LOC_ID               int                  identity,
   LOCATION_ID          int                  not null,
   LOCATION_NAME        varchar(200)         not null,
   constraint PK_LOCATION_NAME primary key (LOC_ID)
)
go

/*==============================================================*/
/* Index: HAVE_FK                                               */
/*==============================================================*/




create nonclustered index HAVE_FK on LOCATION_NAME (LOCATION_ID ASC)
go

/*==============================================================*/
/* Table: REQUEST                                               */
/*==============================================================*/
create table REQUEST (
   REQUEST_ID           int                  identity,
   CLIENT_ID            int                  not null,
   REQUEST_ADDRESS      varchar(100)         not null,
   constraint PK_REQUEST primary key (REQUEST_ID)
)
go

/*==============================================================*/
/* Index: MAKE_FK                                               */
/*==============================================================*/




create nonclustered index MAKE_FK on REQUEST (CLIENT_ID ASC)
go

/*==============================================================*/
/* Table: SEARCH_FOR                                            */
/*==============================================================*/
create table SEARCH_FOR (
   REQUEST_ID           int                  not null,
   WORKER_ID            int                  not null,
   constraint PK_SEARCH_FOR primary key (REQUEST_ID, WORKER_ID)
)
go

/*==============================================================*/
/* Index: SEARCH_FOR_FK                                         */
/*==============================================================*/




create nonclustered index SEARCH_FOR_FK on SEARCH_FOR (REQUEST_ID ASC)
go

/*==============================================================*/
/* Index: SEARCH_FOR2_FK                                        */
/*==============================================================*/




create nonclustered index SEARCH_FOR2_FK on SEARCH_FOR (WORKER_ID ASC)
go

/*==============================================================*/
/* Table: SPECIALITIES                                          */
/*==============================================================*/
create table SPECIALITIES (
   SPECIALITY_ID        int                  identity,
   TASK_ID              int                  null,
   SPECIALITY_NAME      varchar(50)          not null,
   constraint PK_SPECIALITIES primary key (SPECIALITY_ID)
)
go

/*==============================================================*/
/* Index: REQUIRE_FK                                            */
/*==============================================================*/




create nonclustered index REQUIRE_FK on SPECIALITIES (TASK_ID ASC)
go

/*==============================================================*/
/* Table: SUB_TASK                                              */
/*==============================================================*/
create table SUB_TASK (
   TASK_ID              int                  not null,
   NAME                 varchar(50)          not null,
   STATUS               bit                  not null,
   constraint PK_SUB_TASK primary key (TASK_ID)
)
go

/*==============================================================*/
/* Table: TASK                                                  */
/*==============================================================*/
create table TASK (
   TASK_NAME            varchar(50)          not null,
   TASK_ID              int                  identity,
   REQUEST_ID           int                  not null,
   AVG_FEE              int                  not null,
   AVG_TIME_FINISH      datetime             null,
   constraint PK_TASK primary key (TASK_ID)
)
go

/*==============================================================*/
/* Index: CONTAINS_FK                                           */
/*==============================================================*/




create nonclustered index CONTAINS_FK on TASK (REQUEST_ID ASC)
go

/*==============================================================*/
/* Table: WORKER                                                */
/*==============================================================*/
create table WORKER (
   WORKER_ID            int                  identity,
   NAME                 varchar(50)          not null,
   constraint PK_WORKER primary key (WORKER_ID)
)
go

/*==============================================================*/
/* Table: WORK_IN                                               */
/*==============================================================*/
create table WORK_IN (
   WORKER_ID            int                  not null,
   LOCATION_ID          int                  not null,
   constraint PK_WORK_IN primary key (WORKER_ID, LOCATION_ID)
)
go

/*==============================================================*/
/* Index: WORK_IN_FK                                            */
/*==============================================================*/




create nonclustered index WORK_IN_FK on WORK_IN (WORKER_ID ASC)
go

/*==============================================================*/
/* Index: WORK_IN2_FK                                           */
/*==============================================================*/




create nonclustered index WORK_IN2_FK on WORK_IN (LOCATION_ID ASC)
go

alter table AVAILABLE_IN
   add constraint FK_AVAILABL_AVAILABLE_WORKER foreign key (WORKER_ID)
      references WORKER (WORKER_ID)
go

alter table AVAILABLE_IN
   add constraint FK_AVAILABL_AVAILABLE_AVAILABL foreign key (SLOT_ID)
      references AVAILABLE_SLOT (SLOT_ID)
go

alter table HAS
   add constraint FK_HAS_HAS_WORKER foreign key (WORKER_ID)
      references WORKER (WORKER_ID)
go

alter table HAS
   add constraint FK_HAS_HAS2_SPECIALI foreign key (SPECIALITY_ID)
      references SPECIALITIES (SPECIALITY_ID)
go

alter table LOCATION
   add constraint FK_LOCATION_HAVE2_LOCATION foreign key (LOC_ID)
      references LOCATION_NAME (LOC_ID)
go

alter table LOCATION_NAME
   add constraint FK_LOCATION_HAVE_LOCATION foreign key (LOCATION_ID)
      references LOCATION (LOCATION_ID)
go

alter table REQUEST
   add constraint FK_REQUEST_MAKE_CLIENT foreign key (CLIENT_ID)
      references CLIENT (CLIENT_ID)
go

alter table SEARCH_FOR
   add constraint FK_SEARCH_F_SEARCH_FO_REQUEST foreign key (REQUEST_ID)
      references REQUEST (REQUEST_ID)
go

alter table SEARCH_FOR
   add constraint FK_SEARCH_F_SEARCH_FO_WORKER foreign key (WORKER_ID)
      references WORKER (WORKER_ID)
go

alter table SPECIALITIES
   add constraint FK_SPECIALI_REQUIRE_TASK foreign key (TASK_ID)
      references TASK (TASK_ID)
go

alter table SUB_TASK
   add constraint FK_SUB_TASK_ASSIGNED__TASK foreign key (TASK_ID)
      references TASK (TASK_ID)
go

alter table TASK
   add constraint FK_TASK_CONTAINS_REQUEST foreign key (REQUEST_ID)
      references REQUEST (REQUEST_ID)
go

alter table WORK_IN
   add constraint FK_WORK_IN_WORK_IN_WORKER foreign key (WORKER_ID)
      references WORKER (WORKER_ID)
go

alter table WORK_IN
   add constraint FK_WORK_IN_WORK_IN2_LOCATION foreign key (LOCATION_ID)
      references LOCATION (LOCATION_ID)
go
