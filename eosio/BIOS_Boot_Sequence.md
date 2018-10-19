

## eos构建系统启动顺序(BIOS Boot Sequence)

#### 参考链接

###### https://developers.eos.io/eosio-nodeos/docs/bios-boot-sequence
###### /Users/tokenfun/eosio/eos/tutorials/bios-boot-tutorial/bios-boot-tutorial.py

#### 节点路径： 

`````
MAC: ~/Library/Application\ Support/eosio/nodeos/
Ubuntu: ~/.local/share/eosio/nodeos/

###### 清空相关数据
rm -r ~/Library/Application\ Support/eosio/
rm -r ~/eosio-wallet/

````

#### 自动化测试脚步pythons
````
MAC：python3

pip3 install numpy   #### pip install numpy

cd /Users/tokenfun/eosio/eos/tutorials/bios-boot-tutorial
./bios-boot-tutorial.py -a --producer-limit 5 --user-limit 5 --num-voters 3 --num-producers-vote 3 --producer-sync-delay 10


````

#### 0. 清空钱包和多节点进程
````
killall keosd nodeos

export MBP_DIR=/Users/tokenfun/mbp_eosio; 
export MBP_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
mkdir -p ${MBP_DIR}; cd ${MBP_DIR};

````

#### 1. 启动钱包keosd
````
###### 私钥KEY准备
for (( i = 1; i <= 11; i++ )); do cleos create key --to-console | xargs; done
Private key: 5J4PQwZiN6fjTMoZXCgnsqMNw1cvuQ8uDnpJme2JQjs4QXuxExn Public key: EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
Private key: 5K73QPaZ7EpCyEPFmadJiaLfF3DD3shugES7ErT33XUVddKrRmW Public key: EOS6XmgJgrftNdhVCJ2ZoyVc2yhz1zeq7UVJy4wDKmqpNjzqpoj9w
Private key: 5HwnFbF6nqzanQv8Je2aWg8s6isG7hRhYuuqaa3AedVupdKDfPa Public key: EOS5CuW8et4tWNusb9qoubddAuhamuH8dARhHQxwf3Hm5z9uy6rz6
Private key: 5KRRSgiuaJszYgAE6YhZJhmm77ctTNRzqoZ5R1eU3uRifiXkYEz Public key: EOS8AVyHr1aGPQS2vkCwNoDs8pjAPQNUwKCyjCaw4jzWm9R43gc4S
Private key: 5JFYfjQcYE15Nwcm1UZ1uJovPAWykxmz2w94j5PWsYjjooW5tbQ Public key: EOS6ko9ajv9ZSzMVoC3qaGASY5f2ir37ftuu5VKxGnJL19nXg4YMu
Private key: 5HuDVKbovz1Nh44BtGqj6bbcLvnZFjn5Y1jVRUbCkb2e9m9pm6d Public key: EOS6RTkV6kWTToDKRzNMJctXGy3wGZdSLK5fjBW1YG5i34QdYVwma
Private key: 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW Public key: EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz
Private key: 5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy Public key: EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55
Private key: 5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy Public key: EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt
Private key: 5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2 Public key: EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk
Private key: 5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2 Public key: EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk




###### A. 清空钱包
rm -rf ${MBP_DIR}/wallet/; mkdir -p ${MBP_DIR}/wallet/

###### B. 启动keosd并创建钱包 PW5KXKbVY8oidcMQEPZ2H3T1YQBjSzzzU3zua8mgG6PviwpC2HHNq
nohup keosd --unlock-timeout 99999999 --http-server-address 127.0.0.1:6666 --wallet-dir /Users/tokenfun/mbp_eosio/wallet/ 2>&1 >> ${MBP_DIR}/wallet/stderr &

cleos ${MBP_URL} wallet create --file password-wallet.txt
cleos ${MBP_URL} wallet create --to-console
Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5KXKbVY8oidcMQEPZ2H3T1YQBjSzzzU3zua8mgG6PviwpC2HHNq"

###### B. 导入key

cleos ${MBP_URL} wallet import --private-key 5J4PQwZiN6fjTMoZXCgnsqMNw1cvuQ8uDnpJme2JQjs4QXuxExn

cleos ${MBP_URL} wallet import --private-key 5K73QPaZ7EpCyEPFmadJiaLfF3DD3shugES7ErT33XUVddKrRmW
cleos ${MBP_URL} wallet import --private-key 5HwnFbF6nqzanQv8Je2aWg8s6isG7hRhYuuqaa3AedVupdKDfPa
cleos ${MBP_URL} wallet import --private-key 5KRRSgiuaJszYgAE6YhZJhmm77ctTNRzqoZ5R1eU3uRifiXkYEz
cleos ${MBP_URL} wallet import --private-key 5JFYfjQcYE15Nwcm1UZ1uJovPAWykxmz2w94j5PWsYjjooW5tbQ
cleos ${MBP_URL} wallet import --private-key 5HuDVKbovz1Nh44BtGqj6bbcLvnZFjn5Y1jVRUbCkb2e9m9pm6d
cleos ${MBP_URL} wallet import --private-key 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW
cleos ${MBP_URL} wallet import --private-key 5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy
cleos ${MBP_URL} wallet import --private-key 5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy
cleos ${MBP_URL} wallet import --private-key 5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2
cleos ${MBP_URL} wallet import --private-key 5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2

````

#### 2. 启动eosio创世节点
````
###### A. 清空节点
rm -rf ${MBP_DIR}/nodes/; mkdir -p ${MBP_DIR}/nodes/

###### A. 启动eosio节点
rm -rf ${MBP_DIR}/nodes/bp-eosio; mkdir -p ${MBP_DIR}/nodes/bp-eosio

nohup nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-eosio/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-eosio   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-eosio  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8000 --p2p-listen-endpoint 127.0.0.1:9000  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name eosio   --private-key '["EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY","5J4PQwZiN6fjTMoZXCgnsqMNw1cvuQ8uDnpJme2JQjs4QXuxExn"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::history_api_plugin 2>&1 >> ${MBP_DIR}/nodes/bp-eosio/stderr & 

### --p2p-peer-address localhost:9000

````


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

cleos ${MBP_URL} wallet unlock --password PW5KXKbVY8oidcMQEPZ2H3T1YQBjSzzzU3zua8mgG6PviwpC2HHNq

cleos ${MBP_URL} get account eosio -j
cleos ${MBP_URL} create account eosio eosio.bpay EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.msig EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.names EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.ram EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.ramfee EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.saving EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.stake EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.token EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${MBP_URL} create account eosio eosio.vpay EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY


``````

#### 4. 部署eosio.token | eosio.msig 合约

`````
cleos ${MBP_URL} set contract eosio.token /Users/tokenfun/eosio/eos/build/contracts/eosio.token
cleos ${MBP_URL} set contract eosio.msig /Users/tokenfun/eosio/eos/build/contracts/eosio.msig

`````

#### 5. 创建分配 EOS 代币
`````
cleos ${MBP_URL} push action eosio.token create '[ "eosio", "10000000000.0000 EOS" ]' -p eosio.token@active
cleos ${MBP_URL} push action eosio.token issue '[ "eosio", "1000000000.0000 EOS", "memo" ]' -p eosio@active

cleos ${MBP_URL} get currency stats eosio.token EOS
cleos ${MBP_URL} get currency balance eosio.token tester
cleos ${MBP_URL} get currency balance eosio.token eosio
cleos ${MBP_URL} get table eosio.token EOS stat
cleos ${MBP_URL} get table eosio.token eosio accounts

cleos ${MBP_URL} get scope eosio.token
`````

#### 6. 部署 eosio.system 系统合约
`````
cleos ${MBP_URL} set contract eosio /Users/tokenfun/eosio/eos/build/contracts/eosio.system

问题2: Error 3080006: Transaction took too long
解决2: 重拾一次好了，是不是交易时间有限制呢？

问题3: assertion failure with message: unable to find key
解决3: 默认EOS与编译EOS不符合，-DCORE_SYMBOL_NAME=EOS, 或 修改CMakeLists.txt, 将CORE_SYMBLE_NAME配置为'EOS'， 或 ./eosio_build.sh -s EOS


###### 设置eosio.msig为特权帐户

cleos ${MBP_URL} get account eosio.msig
cleos ${MBP_URL} push action eosio setpriv '["eosio.msig", 1]' -p eosio@active
cleos ${MBP_URL} get account eosio.msig


`````

#### 7. 创建Staked抵押账户

`````
users:
Private key: 5K73QPaZ7EpCyEPFmadJiaLfF3DD3shugES7ErT33XUVddKrRmW Public key: EOS6XmgJgrftNdhVCJ2ZoyVc2yhz1zeq7UVJy4wDKmqpNjzqpoj9w
Private key: 5HwnFbF6nqzanQv8Je2aWg8s6isG7hRhYuuqaa3AedVupdKDfPa Public key: EOS5CuW8et4tWNusb9qoubddAuhamuH8dARhHQxwf3Hm5z9uy6rz6
Private key: 5KRRSgiuaJszYgAE6YhZJhmm77ctTNRzqoZ5R1eU3uRifiXkYEz Public key: EOS8AVyHr1aGPQS2vkCwNoDs8pjAPQNUwKCyjCaw4jzWm9R43gc4S
Private key: 5JFYfjQcYE15Nwcm1UZ1uJovPAWykxmz2w94j5PWsYjjooW5tbQ Public key: EOS6ko9ajv9ZSzMVoC3qaGASY5f2ir37ftuu5VKxGnJL19nXg4YMu
Private key: 5HuDVKbovz1Nh44BtGqj6bbcLvnZFjn5Y1jVRUbCkb2e9m9pm6d Public key: EOS6RTkV6kWTToDKRzNMJctXGy3wGZdSLK5fjBW1YG5i34QdYVwma
producer:
Private key: 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW Public key: EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz
Private key: 5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy Public key: EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55
Private key: 5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy Public key: EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt
Private key: 5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2 Public key: EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk
Private key: 5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2 Public key: EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk

###### cleos system newaccount eosio --transfer accountnum55 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 EOS" --stake-cpu "100000.0000 EOS" --buy-ram-kbytes 8192

cleos ${MBP_URL} system newaccount --transfer eosio user21 EOS6XmgJgrftNdhVCJ2ZoyVc2yhz1zeq7UVJy4wDKmqpNjzqpoj9w --stake-net "146382842.7954 EOS" --stake-cpu "146382842.7955 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user21 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user22 EOS5CuW8et4tWNusb9qoubddAuhamuH8dARhHQxwf3Hm5z9uy6rz6 --stake-net "146382842.7954 EOS" --stake-cpu "146382842.7955 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user22 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user23 EOS8AVyHr1aGPQS2vkCwNoDs8pjAPQNUwKCyjCaw4jzWm9R43gc4S --stake-net "146382842.7954 EOS" --stake-cpu "146382842.7955 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user23 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user24 EOS6ko9ajv9ZSzMVoC3qaGASY5f2ir37ftuu5VKxGnJL19nXg4YMu --stake-net "19620199.5302 EOS" --stake-cpu "19620199.5302 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user24 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user25 EOS6RTkV6kWTToDKRzNMJctXGy3wGZdSLK5fjBW1YG5i34QdYVwma --stake-net "19620199.5302 EOS" --stake-cpu "19620199.5302  EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user25 "10.0000 EOS"

cleos ${MBP_URL} system newaccount --transfer eosio producer21 EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz --stake-net "9810277.0101 EOS" --stake-cpu "9810277.0101 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer21 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer22 EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55 --stake-net "9810277.0101 EOS" --stake-cpu "9810277.0101 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer22 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer23 EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt --stake-net "1867182.6445 EOS" --stake-cpu "1867182.6445 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer23 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer24 EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk --stake-net "81023.1884 EOS" --stake-cpu "81023.1884 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer24 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer25 EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk --stake-net "25536.1884 EOS" --stake-cpu "25536.1884  EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer25 "10.0000 EOS"


问题3: assertion failure with message: overdrawn balance
解决3: 调整平衡理论？不太懂呢

`````

#### 8. 注册生产者producers

`````

cleos ${MBP_URL} system regproducer producer21 EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz https://producer21.com/EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz
cleos ${MBP_URL} system regproducer producer22 EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55 https://producer22.com/EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55
cleos ${MBP_URL} system regproducer producer23 EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt https://producer23.com/EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt
cleos ${MBP_URL} system regproducer producer24 EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk https://producer24.com/EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk
cleos ${MBP_URL} system regproducer producer25 EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk https://producer25.com/EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk

###### B. 列出producers

cleos ${MBP_URL} system listproducers

`````

#### 9. 启动producers
`````
producer:
Private key: 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW Public key: EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz
Private key: 5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy Public key: EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55
Private key: 5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy Public key: EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt
Private key: 5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2 Public key: EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk
Private key: 5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2 Public key: EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk


rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer21; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer21
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer21/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer21   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer21  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8001 --p2p-listen-endpoint 127.0.0.1:9001  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer21   --private-key '["EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz","5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000

rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer22; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer22
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer22/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer22   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer22  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8002 --p2p-listen-endpoint 127.0.0.1:9002  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer22   --private-key '["EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55","5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001

rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer23; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer23
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer23/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer23   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer23  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8003 --p2p-listen-endpoint 127.0.0.1:9003  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer23   --private-key '["EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt","5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002


rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer24; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer24
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer24/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer24   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer24  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8004 --p2p-listen-endpoint 127.0.0.1:9004  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer24   --private-key '["EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk","5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002 --p2p-peer-address localhost:9003

rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer25; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer25
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer25/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer25   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer25  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8005 --p2p-listen-endpoint 127.0.0.1:9005  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer25   --private-key '["EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk","5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002 --p2p-peer-address localhost:9003 --p2p-peer-address localhost:9004


`````

#### 10. 投票producer

`````

cleos ${MBP_URL} system voteproducer prods user21 producer21 producer22 producer23 
cleos ${MBP_URL} system voteproducer prods user22 producer21 producer22 producer24 
cleos ${MBP_URL} system voteproducer prods user23 producer21 producer24 producer23 
cleos ${MBP_URL} system voteproducer prods user24 producer21 producer22 producer23 
cleos ${MBP_URL} system voteproducer prods user25 producer24 
cleos ${MBP_URL} system listproducers

######  cleos ${MBP_URL} system listproducers


`````

#### 11. 赎回矿工费用
`````

cleos ${MBP_URL} get table eosio eosio producers -l 100
cleos ${MBP_URL} system claimrewards -j producer21

`````

#### 12. 代理投票
`````
cleos ${MBP_URL} system listproducers
cleos ${MBP_URL} system voteproducer prods producer21 producer22 producer23 producer24 producer25
cleos ${MBP_URL} system regproxy producer21
cleos ${MBP_URL} system voteproducer proxy user21 producer21
cleos ${MBP_URL} system voteproducer proxy user22 producer21
cleos ${MBP_URL} system voteproducer proxy user23 producer21
cleos ${MBP_URL} system voteproducer proxy user24 producer21
cleos ${MBP_URL} system voteproducer proxy user25 producer21

`````

#### 12. Resign eosio
`````

###### 更新 'eosio' => 'eosio.prods'
cleos ${MBP_URL} get account eosio
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio.prods", "permission": "active"}}]}}' -p eosio@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio.prods", "permission": "active"}}]}}' -p eosio@active
cleos ${MBP_URL} get account eosio

###### 更新 'eosio.bpay|msig|names|...' => 'eosio'
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.bpay", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.bpay@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.bpay", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.bpay@active
cleos ${MBP_URL} get account eosio.bpay

cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.msig", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.msig@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.msig", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.msig@active
cleos ${MBP_URL} get account eosio.msig
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.names", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.names@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.names", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.names@active
cleos ${MBP_URL} get account eosio.names
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.ram", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ram@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.ram", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ram@active
cleos ${MBP_URL} get account eosio.ram
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.ramfee", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ramfee@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.ramfee", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ramfee@active
cleos ${MBP_URL} get account eosio.ramfee
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.saving", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.saving@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.saving", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.saving@active
cleos ${MBP_URL} get account eosio.saving
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.stake", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.stake@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.stake", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.stake@active
cleos ${MBP_URL} get account eosio.stake
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.token", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.token@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.token", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.token@active
cleos ${MBP_URL} get account eosio.token
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.vpay", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.vpay@owner
cleos ${MBP_URL} push action eosio updateauth '{"account": "eosio.vpay", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.vpay@active
cleos ${MBP_URL} get account eosio.vpay


`````

#### 13. Replace system contract using msig
`````

cleos ${MBP_URL} push action eosio buyrambytes '["producer211a", "useraaaaaaaa", 200000]' -p producer211a

cleos ${MBP_URL} multisig propose fast.unstake '[{"actor": "producer211a", "permission": "active"}, {"actor": "producer211b", "permission": "active"}, {"actor": "producer211c", "permission": "active"}, {"actor": "producer211d", "permission": "active"}, {"actor": "producer211e", "permission": "active"}, {"actor": "producer211f", "permission": "active"}, {"actor": "producer211g", "permission": "active"}, {"actor": "producer211h", "permission": "active"}, {"actor": "producer211i", "permission": "active"}, {"actor": "producer211j", "permission": "active"}, {"actor": "producer211k", "permission": "active"}, {"actor": "producer211l", "permission": "active"}, {"actor": "producer211m", "permission": "active"}, {"actor": "producer211n", "permission": "active"}, {"actor": "producer211o", "permission": "active"}, {"actor": "producer211p", "permission": "active"}, {"actor": "producer211q", "permission": "active"}, {"actor": "producer211r", "permission": "active"}, {"actor": "producer211s", "permission": "active"}, {"actor": "producer211t", "permission": "active"}, {"actor": "producer211u", "permission": "active"}, {"actor": "producer211v", "permission": "active"}, {"actor": "producer211w", "permission": "active"}, {"actor": "producer211x", "permission": "active"}, {"actor": "producer211y", "permission": "active"}, {"actor": "producer211z", "permission": "active"}, {"actor": "producer2111", "permission": "active"}, {"actor": "producer2112", "permission": "active"}, {"actor": "producer2113", "permission": "active"}, {"actor": "producer2114", "permission": "active"}]'  '[{"actor": "eosio", "permission": "active"}]' eosio setcode '{"account": "eosio", "vmtype": 0, "vmversion": 0, "code": "xxxxxx"}'  -p useraaaaaaaa

cleos ${MBP_URL} multisig approve useraaaaaaaa fast.unstake '{"actor": "producer211a", "permission": "active"}' -p producer211a
cleos ${MBP_URL} multisig approve useraaaaaaaa fast.unstake '{"actor": "producer211b", "permission": "active"}' -p producer211b
cleos ${MBP_URL} multisig approve useraaaaaaaa fast.unstake '{"actor": "producer211c", "permission": "active"}' -p producer211c
cleos ${MBP_URL} multisig approve useraaaaaaaa fast.unstake '{"actor": "producer211d", "permission": "active"}' -p producer211d
cleos ${MBP_URL} multisig approve useraaaaaaaa fast.unstake '{"actor": "producer211e", "permission": "active"}' -p producer211e

cleos ${MBP_URL} multisig exec useraaaaaaaa fast.unstake -p useraaaaaaaa
cleos ${MBP_URL} multisig cancel useraaaaaaaa fast.unstake -p useraaaaaaaa
cleos ${MBP_URL} multisig review useraaaaaaaa fast.unstake


cleos ${MBP_URL} get code eosio
code hash: d8324003310065dd1d549a6929564c095c30e3a28954ec54dd72ced6cfaf08b3



`````
















