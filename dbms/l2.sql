CREATE TABLE employee(empno INT,empname VARCHAR(10) NOT NULL, Gender char(1) NOT NULL, Salary INT NOT NULL , address VARCHAR(20) NOT NULL, dno INT,PRIMARY KEY (empno) );

CREATE TABLE department(deptno INT NOT NULL,deptname VARCHAR(10) NOT NULL UNIQUE, location VARCHAR(20),PRIMARY KEY (deptno) );

ALTER TABLE Employee add constraint fkdno foreign key (dno) references department(deptno);

insert into department values (11, 'cse', 'manipal');
insert into department values (12, 'mech', 'manipal');
insert into department values (13, 'ece', 'mangalore');
insert into department values (14, 'finance', 'manipal');
insert into department values (15, 'sales', 'delhi');

insert into employee values (1, 'ram', 'm', 1000, 'manipal' , 11);
insert into employee values (2, 'riddhi', 'f', 1200, 'manipal' , 11);
insert into employee values (3, 'shruti', 'f', 1100, 'mangalore' , 13);
insert into employee values (4, 'garv', 'm', 1600, 'manipal' , 12);
insert into employee values (5, 'dua', 'f', 900, 'manipal' , 15);
insert into employee values (6, 'andy', 'm', 1900, 'delhi' , 15);
insert into employee values (7, 'shriya', 'f', 9300, 'manipal' , 14);


SQL> insert into employee values (15, 'nody', 'f', 900, 'manipal' , 23);
insert into employee values (15, 'nody', 'f', 900, 'manipal' , 23)
*
ERROR at line 1:
ORA-02291: integrity constraint (G25.SYS_C0012847) violated - parent key not
found
Depart. id = 23 doesnt exist


SQL>  insert into employee values (8, 'nody', 'f', NULL , 'manipal' , 14);
 insert into employee values (8, 'nody', 'f', NULL , 'manipal' , 14)
                                              *
ERROR at line 1:
ORA-01400: cannot insert NULL into ("G25"."EMPLOYEE"."SALARY")
salary cant be NULL


SQL>  insert into employee values (3, 'nody', 'f', 2033 , 'manipal' , 14);
 insert into employee values (3, 'nody', 'f', 2033 , 'manipal' , 14)
*
ERROR at line 1:
ORA-02291: integrity constraint (G25.SYS_C0012847) violated - parent key not
found
emp_no is a primary key, contains unique values only


SQL> insert into department values (17, 'sales', 'ggn');
insert into department values (17, 'sales', 'ggn')
*
ERROR at line 1:
ORA-00001: unique constraint (G25.SYS_C0012846) violated
dept_name is candidate key, must contain unique values


SQL> delete from department where deptno = 11;
delete from department where deptno = 11
*
ERROR at line 1:
ORA-02292: integrity constraint (G25.SYS_C0012847) violated - child record
found


ALTER TABLE employee DROP constraint fkdno;

ALTER TABLE Employee add constraint fkdno foreign key (dno) references department(deptno) ON DELETE CASCADE;

ALTER TABLE Employee modify salary default 10000;