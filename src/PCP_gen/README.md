#Database

##installation:
Install mysql server edition from [here](https://dev.mysql.com/downloads/mysql/)    
Go [here](https://codeforces.com/blog/entry/48328?locale=ru) for how to install mysql cppconnector

##setup:
Run the script CreateDB.sh in terminal:
```
sudo ./CreateDB.sh
```
Might need to make it executable with:
```
sudo chmod a+x CreateDB.sh
```

##done!
You can verify if it worked by going in the list of users and checking that PCPadmin is present:
```
mysql -u yourusername -p
use mysql
select user from user;
```

##db specs:
tables:
instances(id, pairs, sol_len)

max sol len = 65535

max #of instances = 16777215 (should be good enough lol)

max pcp instance size is 6, 6 (or equivalent) or 84 characters

pcp instances encoded with ',' between every word e.g:

| a   | b   | c   |
|-----|-----|-----|
| 101 | 0   | 1   |
| 0   | 1   | 101 |
is encoded with the string:
"101,0,0,1,1,101"