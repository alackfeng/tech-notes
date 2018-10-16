

## eos合约eos.multisig使用说明


#### 0. 清理旧数据

````
rm -rf /Users/tokenfun/Library/Application\ Support/eosio/
rm -rf /Users/tokenfun/eosio-wallet/

````

#### 1. 启动eos节点 nodeos

````
cd /Users/tokenfun/eosio/eos/build/programs/nodeos
#./nodeos -e -p eosio
./nodeos -e -p eosio --plugin eosio::chain_api_plugin --plugin eosio::net_api_plugin --plugin eosio::history_api_plugin --plugin eosio::http_plugin --plugin eosio::producer_plugin

Q1. 3020000 fork_database_exception: Fork database exception
fork database is inconsistent with shared memory
A1. 尝试： --replay --fix-reversible-blocks   或者	--delete-all-blocks


````

#### 3. 创建相关账号

````
cd /Users/tokenfun/eosio/eos/build/programs/cleos

./cleos wallet create --file /Users/tokenfun/eosio-wallet/wallet_defalut_password
./cleos wallet create -n testmultisig --file /Users/tokenfun/eosio-wallet/wallet_testmultisig_password
./cleos wallet list

cat /Users/tokenfun/eosio-wallet/wallet_defalut_password
PW5HxYNRNvKYLwNbz7vs56sWSiHF4CzZAd2KL99vndveRYfiGjTPT

####导入eosio账号私钥
./cleos --wallet-url http://127.0.0.1:8900 wallet import --private-key 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
imported private key for: EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV


./cleos create key --to-console
Private key: 5JVxSTbxDekP7UfwopGg9onCWqEWqpwyueoyuoNknALmGEUDJZt
Public key: EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc


./cleos wallet import -n default --private-key 5JVxSTbxDekP7UfwopGg9onCWqEWqpwyueoyuoNknALmGEUDJZt
./cleos wallet keys

./cleos create account eosio treasury EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos --wallet-url http://127.0.0.1:8900 create account eosio tester EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account treasury feng EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
x

````

#### 3. 部署相关合约

````

./cleos create account eosio eosio.bpay EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.msig EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.ram EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.ramfee EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.saving EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.stake EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.token EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc
./cleos create account eosio eosio.vpay EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc

./cleos get account eosio.token

./cleos get code eosio.token
code hash: 0000000000000000000000000000000000000000000000000000000000000000
./cleos set contract eosio.token /Users/tokenfun/eosio/eos/build/contracts/eosio.token
./cleos get code eosio.token
code hash: 641f336aa1d08526201599c3c0ddb7a646e5ac8f9fd2493f56414d0422a0f957


./cleos push action eosio.token create '[ "treasury", "10000000000.0000 EOS" ]' -p eosio.token
./cleos push action eosio.token issue '[ "treasury", "1000000000.0000 EOS", "memo first send" ]' -p treasury
./cleos push action eosio.token issue '[ "tester", "100.1111 EOS", "memo second send" ]' -p treasury
./cleos push action eosio.token transfer '[ "treasury", "tester", "100.2222 EOS", "transfer test" ]' -p treasury


./cleos get currency stats eosio.token EOS
./cleos get currency balance eosio.token treasury
./cleos get currency balance eosio.token tester
./cleos get table eosio.token treasury accounts
./cleos get table eosio.token tester accounts
./cleos get table eosio.token EOS stat
./cleos get table eosio.token SYS stat





````


#### 4. 多重签名提案

````
./cleos get code eosio.msig
./cleos set contract eosio.msig /Users/tokenfun/eosio/eos/build/contracts/eosio.msig
./cleos get code eosio.msig
code hash: 5cf017909547b2d69cee5f01c53fe90f3ab193c57108f81a17f0716a4c83f9c0


./cleos multisig propose test '[{"actor": "treasury", "permission": "active"}]' '[{"actor": "treasury", "permission": "active"}]' eosio.token issue '{"to": "tester", "quantity": "1000.0000 EOS", "memo": " token.msig"}' -p treasury
./cleos multisig review tester test
./cleos multisig approve treasury test '{"actor": "treasury", "permission": "active"}' -p treasury
#./cleos multisig unapprove tester test '{"actor": "treasury", "permission": "active"}' -p treasury
./cleos multisig exec treasury test treasury -p treasury

./cleos multisig cancel tester test -p tester


cleos ${WALLET_URL} get table eosio.msig treasury proposal
cleos ${WALLET_URL} get table eosio.msig treasury approvals


------------------- multisig eosio.token issue

###### 多重签名操作

cleos ${WALLET_URL} get currency balance eosio.token eosio
cleos ${WALLET_URL} push action eosio.token issue '[ "eosio", "1000.0000 SYS", "memo orginal" ]' -p eosio@active

cleos ${WALLET_URL} multisig propose tokenpropose '[{"actor": "useraaaaaaaa", "permission": "active"},{"actor": "producer111b", "permission": "active"},{"actor": "eosio", "permission": "active"}]' '[{"actor": "eosio", "permission": "active"}]' eosio.token issue '{"to": "eosio", "quantity": "1000.0000 SYS", "memo": " token proposer test msig "}' -p useraaaaaaaa
cleos ${WALLET_URL} multisig review useraaaaaaaa tokenpropose
cleos ${WALLET_URL} multisig approve useraaaaaaaa tokenpropose '{"actor": "useraaaaaaaa", "permission": "active"}' -p useraaaaaaaa
cleos ${WALLET_URL} multisig approve useraaaaaaaa tokenpropose '{"actor": "eosio", "permission": "active"}' -p eosio
cleos ${WALLET_URL} multisig exec useraaaaaaaa tokenpropose useraaaaaaaa -p useraaaaaaaa

cleos ${WALLET_URL} multisig unapprove useraaaaaaaa tokenpropose '{"actor": "useraaaaaaaa", "permission": "active"}' -p useraaaaaaaa
cleos ${WALLET_URL} multisig cancel useraaaaaaaa tokenpropose -p useraaaaaaaa


cleos ${WALLET_URL} get table eosio.msig useraaaaaaaa proposal
cleos ${WALLET_URL} get table eosio.msig useraaaaaaaa approvals

cleos ${WALLET_URL} get currency balance eosio.token eosio



-----------------------

###### 多重签名转账操作

cleos ${WALLET_URL} get account useraaaaaaae
cleos ${WALLET_URL} get account useraaaaaaad
cleos ${WALLET_URL} get account useraaaaaaac

cleos ${WALLET_URL} set account permission useraaaaaaae owner '{"threshold":2,"keys":[],"accounts":[{"permission":{"actor":"useraaaaaaac","permission":"owner"},"weight":1},{"permission":{"actor":"useraaaaaaad","permission":"owner"},"weight":1}],"waits":[]}' -p useraaaaaaae@owner
cleos ${WALLET_URL} set account permission useraaaaaaae active '{"threshold":1,"keys":[],"accounts":[{"permission":{"actor":"useraaaaaaac","permission":"owner"},"weight":1},{"permission":{"actor":"useraaaaaaad","permission":"owner"},"weight":1}],"waits":[]}' -p useraaaaaaae@owner

cleos ${WALLET_URL} get account useraaaaaaae

cleos ${WALLET_URL} get currency balance eosio.token useraaaaaaac
cleos ${WALLET_URL} push action eosio.token transfer '[ "useraaaaaaae", "useraaaaaaac", "100.0000 SYS", "original test"]' -p useraaaaaaae@active

cleos ${WALLET_URL} multisig propose transpropose '[{"actor": "useraaaaaaac", "permission": "owner"},{"actor": "useraaaaaaad", "permission": "owner"}]' '[{"actor": "useraaaaaaae", "permission": "active"}]' eosio.token transfer '{"from": "useraaaaaaae", "to": "useraaaaaaac", "quantity": "100.0000 SYS", "memo": " token transfer proposer test msig "}' -p useraaaaaaaa
cleos ${WALLET_URL} multisig review useraaaaaaaa transpropose
cleos ${WALLET_URL} multisig approve useraaaaaaaa transpropose '{"actor": "useraaaaaaac", "permission": "owner"}' -p useraaaaaaac@owner
cleos ${WALLET_URL} multisig approve useraaaaaaaa transpropose '{"actor": "useraaaaaaad", "permission": "owner"}' -p useraaaaaaad@owner
cleos ${WALLET_URL} multisig exec useraaaaaaaa transpropose useraaaaaaaa -p useraaaaaaaa

#cleos ${WALLET_URL} multisig unapprove useraaaaaaaa transpropose '{"actor": "useraaaaaaad", "permission": "active"}' -p useraaaaaaad@owner
cleos ${WALLET_URL} multisig cancel useraaaaaaaa transpropose -p useraaaaaaaa


cleos ${WALLET_URL} get table eosio.msig useraaaaaaaa proposal
cleos ${WALLET_URL} get table eosio.msig useraaaaaaaa approvals

cleos ${WALLET_URL} get currency balance eosio.token useraaaaaaac


cleos ${WALLET_URL} set account permission useraaaaaaae active '{"threshold":2,"keys":[{"key": "EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc","weight": 1}],"accounts":[{"permission":{"actor":"useraaaaaaac","permission":"active"},"weight":1},{"permission":{"actor":"useraaaaaaae","permission":"active"},"weight":1}],"waits":[]}' -p useraaaaaaae@owner
cleos ${WALLET_URL} get account useraaaaaaae



-------------------


Q1. Error 3090003: Provided keys, permissions, and delays do not satisfy declared authorizations
A1: Fixed. All the signature account should hava "eosio.msig@eosio.code" permission now.
./cleos set account permission treasury active '{"threshold": 1, "keys":[{"key":"EOS7ghjmTj7d9u8upMLuuxTs59AFutmc24bntqDZuSfiXDrDnucPc", "weight":1}], "accounts":[{"permission":{"actor":"eosio.msig","permission":"eosio.code"},"weight":1}], "waits":[] }' owner -p treasury@owner
未解决呢？？？？
https://github.com/EOSIO/eos/issues/4964

## 账户的权限管理还需要研究一下呢？？？



````


