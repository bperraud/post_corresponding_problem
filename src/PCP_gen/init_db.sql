use mysql;
create user if not exists 'PCPadmin' identified by 'AXaHUKc])n2D%t*"T6Ve';  #unified password for everyone
CREATE DATABASE if not exists PCP;

grant all privileges on PCP to 'PCPadmin'; #all privileges on PCP tables for admin

use PCP;

create table if not exists instances(
    id mediumint not null auto_increment,
    pairs varchar(84) not null,
    sol_len smallint,
    primary key (id)
    );