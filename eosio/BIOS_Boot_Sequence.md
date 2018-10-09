

## eos构建启动顺序

#### https://developers.eos.io/eosio-nodeos/docs/bios-boot-sequence

#### 节点路径： ~/Library/Application\ Support/eosio/nodeos
rm -r ~/Library/Application\ Support/eosio/
rm -r ~/eosio-wallet/
rm -r ~/eosio_test/accountnum11/; mkdir ~/eosio_test/accountnum11


#### 0. 自动化测试脚步python
````
pip3 install numpy   #### pip install numpy

cd /Users/tokenfun/eosio/eos/tutorials/bios-boot-tutorial
./bios-boot-tutorial.py -a --producer-limit 10 --user-limit 10 --num-voters 5 --num-producers-vote 5 --producer-sync-delay 10


````


#### 1. 配置初始的nodeos节点
````
#### A. 创建配置和数据目录 --config-dir  --data-dir

mkdir ~/eosio_test
for (( i = 1; i <= 5; i++ )); do for (( j = 1 ; j <=5 ; j++ )); do mkdir ~/eosio_test/accountnum$i$j; done; done


#### B. 预备P2P网络的IP地址

--p2p-peer-address localhost:9011 --p2p-peer-address localhost:9013 --p2p-peer-address localhost:9014

OR

vi config.ini ====>
bnet-endpoint = 0.0.0.0:4321
enable-stale-production = true
signature-provider = EOS52rXAFcoR8xGv6VqGffpTLLwNp11P6uWcUtE9SDcT4124JXRSE=KEY:5Kksf4Qu7xsQPJBMFBWmszpWL1PFmiZbGFoEBFf7iCV5VjGiSy4
p2p-peer-address = localhost:9011
p2p-peer-address = localhost:9013
p2p-peer-address = localhost:9014
plugin = eosio::producer_plugin
plugin = eosio::chain_api_plugin
plugin = eosio::http_plugin
plugin = eosio::history_api_plugin

<====

```` 


#### 2. 启动创世节点

`````
#### A. 创建钱包 PW5JvF22gHdZG6WHorpxnx7yo4vyES8XjDGhpzREYyDhUgB6nZDc4

###### killall keosd
cleos wallet create --to-console
"/usr/local/eosio/bin/keosd" launched
Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5JvF22gHdZG6WHorpxnx7yo4vyES8XjDGhpzREYyDhUgB6nZDc4"
tokenfundeMBP:~ tokenfun$

#### B. 配置genesis.json

{
  "initial_timestamp": "2018-10-06T12:00:00.000",
  "initial_key": "EOS52rXAFcoR8xGv6VqGffpTLLwNp11P6uWcUtE9SDcT4124JXRSE",
  "initial_configuration": {
    "max_block_net_usage": 1048576,
    "target_block_net_usage_pct": 1000,
    "max_transaction_net_usage": 524288,
    "base_per_transaction_net_usage": 12,
    "net_usage_leeway": 500,
    "context_free_discount_net_usage_num": 20,
    "context_free_discount_net_usage_den": 100,
    "max_block_cpu_usage": 100000,
    "target_block_cpu_usage_pct": 500,
    "max_transaction_cpu_usage": 50000,
    "min_transaction_cpu_usage": 100,
    "max_transaction_lifetime": 3600,
    "deferred_trx_expiration_window": 600,
    "max_transaction_delay": 3888000,
    "max_inline_action_size": 4096,
    "max_inline_action_depth": 4,
    "max_authority_depth": 6
  },
  "initial_chain_id": "0000000000000000000000000000000000000000000000000000000000000000"
}


#### C. 创建eosio账号的key

cleos create key --to-console
Private key: 5Kksf4Qu7xsQPJBMFBWmszpWL1PFmiZbGFoEBFf7iCV5VjGiSy4
Public key: EOS52rXAFcoR8xGv6VqGffpTLLwNp11P6uWcUtE9SDcT4124JXRSE

#### D. 启动genesis节点



####### 废弃：nodeos -e -p eosio --private-key '[ "EOS52rXAFcoR8xGv6VqGffpTLLwNp11P6uWcUtE9SDcT4124JXRSE","5Kksf4Qu7xsQPJBMFBWmszpWL1PFmiZbGFoEBFf7iCV5VjGiSy4" ]' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --plugin eosio::history_api_plugin

#### nodeos -e -p eosio --signature-provider 'EOS52rXAFcoR8xGv6VqGffpTLLwNp11P6uWcUtE9SDcT4124JXRSE=KEY:5Kksf4Qu7xsQPJBMFBWmszpWL1PFmiZbGFoEBFf7iCV5VjGiSy4' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --plugin eosio::history_api_plugin


#### rm -r ~/eosio_test/accountnum11/; mkdir ~/eosio_test/accountnum11
nodeos -e -p eosio --genesis-json ~/eosio_test/genesis.json --config-dir ~/eosio_test/accountnum11/config  --data-dir ~/eosio_test/accountnum11/data --signature-provider 'EOS52rXAFcoR8xGv6VqGffpTLLwNp11P6uWcUtE9SDcT4124JXRSE=KEY:5Kksf4Qu7xsQPJBMFBWmszpWL1PFmiZbGFoEBFf7iCV5VjGiSy4' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --plugin eosio::history_api_plugin


nodeos -e -p eosio --genesis-json ~/eosio_test/config/genesis.json --config-dir ~/eosio_test/config  --data-dir ~/eosio_test/accountnum11/data
nodeos -e -p eosio --config-dir ~/eosio_test/config  --data-dir ~/eosio_test/accountnum11/data


`````


#### 3. 创建重要的系统账号

  eosio.bpay
  eosio.msig
  eosio.names
  eosio.ram
  eosio.ramfee
  eosio.saving
  eosio.stake
  eosio.token
  eosio.vpay


`````
cleos create key --to-console
Private key: 5Jo7Tto99DUWrrNGRAb8F6UZmusaRFvEwZpgi41Cdy5LA2GpXDu
Public key: EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx

cleos wallet unlock --password PW5JvF22gHdZG6WHorpxnx7yo4vyES8XjDGhpzREYyDhUgB6nZDc4
cleos wallet import --private-key 5Kksf4Qu7xsQPJBMFBWmszpWL1PFmiZbGFoEBFf7iCV5VjGiSy4
cleos wallet import --private-key 5Jo7Tto99DUWrrNGRAb8F6UZmusaRFvEwZpgi41Cdy5LA2GpXDu

cleos get account eosio
cleos create account eosio eosio.bpay EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.msig EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.names EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.ram EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.ramfee EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.saving EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.stake EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.token EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
cleos create account eosio eosio.vpay EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx



``````

#### 4. 部署eosio.token 合约

`````
cleos set contract eosio.token /Users/tokenfun/eosio/eos/build/contracts/eosio.token

#### 5. 部署 eosio.msig 合约
cleos set contract eosio.msig /Users/tokenfun/eosio/eos/build/contracts/eosio.msig


#### 6. 创建分配 SYS 代币

cleos push action eosio.token create '[ "eosio", "10000000000.0000 SYS" ]' -p eosio.token@active
cleos push action eosio.token issue '[ "eosio", "1000000000.0000 SYS", "memo" ]' -p eosio@active

cleos get currency stats eosio.token SYS
cleos get currency balance eosio.token tester
cleos get table eosio.token SYS stat
cleos get table eosio.token eosio accounts

#### 7. 部署 eosio.system 合约

cleos set contract eosio /Users/tokenfun/eosio/eos/build/contracts/eosio.system

问题2: Error 3080006: Transaction took too long
解决2: 重拾一次好了，是不是交易时间有限制呢？

`````

#### 8. 单一BP过度到多BP

`````

###### 使 eosio.msig 有权限账户
cleos push action eosio setpriv '["eosio.msig", 1]' -p eosio@active

tokenfundeMBP:~ tokenfun$ cleos get account eosio.msig
created: 2018-10-08T10:05:14.000
privileged: true
permissions:
     owner     1:    1 EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
        active     1:    1 EOS5L4yv9yeWGcU3rocZavBn9YFwRQ8b2VFnC8kNs3uJioeviPntx
memory:



`````

#### 9. 抵押token，扩展网络
#### 10. 创建抵押账户

`````
###### A. 创建抵押账户
cleos create key --to-console
Private key: 5JrzuVDbjLzQyWyW2WDcJ1FwJZBnHXQTpvByfadFArWcGLZDcWr
Public key: EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb

cleos wallet import --private-key 5JrzuVDbjLzQyWyW2WDcJ1FwJZBnHXQTpvByfadFArWcGLZDcWr

cleos system newaccount eosio --transfer accountnum11 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192
cleos system newaccount eosio --transfer accountnum22 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192
cleos system newaccount eosio --transfer accountnum33 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192
cleos system newaccount eosio --transfer accountnum44 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192
cleos system newaccount eosio --transfer accountnum55 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192


cleos create key --to-console
Private key: 5K2XkKgNaqU8sL1zoJtCyXH3ZodToR6qGyqBNuW88k4jJkrwF3A
Public key: EOS8gfEnXbJoYPudUtdbznVdH9Hp5VhKGuexgkmGoyrTvBeRSF2ki

cleos wallet import --private-key 5K2XkKgNaqU8sL1zoJtCyXH3ZodToR6qGyqBNuW88k4jJkrwF3A

cleos system newaccount eosio --transfer accountnum55 EOS8gfEnXbJoYPudUtdbznVdH9Hp5VhKGuexgkmGoyrTvBeRSF2ki --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192

`````

#### 11. 选举BP

`````
###### A. 注册生产者producer

cleos system regproducer accountnum11 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb https://accountnum11.com/EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb
cleos system regproducer accountnum22 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb https://accountnum11.com/EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb
cleos system regproducer accountnum33 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb https://accountnum11.com/EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb
cleos system regproducer accountnum44 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb https://accountnum11.com/EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb
cleos system regproducer accountnum55 EOS8gfEnXbJoYPudUtdbznVdH9Hp5VhKGuexgkmGoyrTvBeRSF2ki https://accountnum11.com/EOS8gfEnXbJoYPudUtdbznVdH9Hp5VhKGuexgkmGoyrTvBeRSF2ki

###### B. 列出producers

cleos system listproducers

###### C. 启动producers们

nodeos  --config-dir ~/eosio_test/accountnum55/config --data-dir ~/eosio_test/accountnum55/data --http-server-address 127.0.0.1:8011 --p2p-listen-endpoint 127.0.0.1:9011 --enable-stale-production --producer-name accountnum55 --signature-provider 'EOS8gfEnXbJoYPudUtdbznVdH9Hp5VhKGuexgkmGoyrTvBeRSF2ki=KEY:5K2XkKgNaqU8sL1zoJtCyXH3ZodToR6qGyqBNuW88k4jJkrwF3A' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9022  --p2p-peer-address localhost:9033  --p2p-peer-address localhost:9044



nodeos --genesis-json ~/eosio_test/accountnum22/genesis.json --config-dir ~/eosio_test/accountnum22/config --data-dir ~/eosio_test/accountnum22/data --http-server-address 127.0.0.1:8022 --p2p-listen-endpoint 127.0.0.1:9022 --enable-stale-production --producer-name accountnum22 --signature-provider 'EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb=KEY:5JrzuVDbjLzQyWyW2WDcJ1FwJZBnHXQTpvByfadFArWcGLZDcWr' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --p2p-peer-address localhost:9011  --p2p-peer-address localhost:9033  --p2p-peer-address localhost:9044


nodeos --genesis-json ~/eosio_test/accountnum33/genesis.json --config-dir ~/eosio_test/accountnum33/config --data-dir ~/eosio_test/accountnum33/data --http-server-address 127.0.0.1:8033 --p2p-listen-endpoint 127.0.0.1:9033 --enable-stale-production --producer-name accountnum33 --signature-provider 'EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb=KEY:5JrzuVDbjLzQyWyW2WDcJ1FwJZBnHXQTpvByfadFArWcGLZDcWr' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --p2p-peer-address localhost:9011  --p2p-peer-address localhost:9022  --p2p-peer-address localhost:9044

nodeos --genesis-json ~/eosio_test/accountnum44/genesis.json --config-dir ~/eosio_test/accountnum44/config --data-dir ~/eosio_test/accountnum44/data --http-server-address 127.0.0.1:8044 --p2p-listen-endpoint 127.0.0.1:9044 --enable-stale-production --producer-name accountnum44 --signature-provider 'EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb=KEY:5JrzuVDbjLzQyWyW2WDcJ1FwJZBnHXQTpvByfadFArWcGLZDcWr' --plugin eosio::producer_plugin --plugin eosio::chain_api_plugin --plugin eosio::http_plugin --p2p-peer-address localhost:9011  --p2p-peer-address localhost:9022  --p2p-peer-address localhost:9033



`````

#### 12. Resign eosio
`````
cleos push action eosio updateauth '{"account": "eosio", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio.prods", "permission": "active"}}]}}' -p eosio@owner
cleos push action eosio updateauth '{"account": "eosio", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio.prods", "permission": "active"}}]}}' -p eosio@active


`````










