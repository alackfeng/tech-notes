

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
./bios-boot-tutorial.py -a --producer-limit 10 --user-limit 10 --num-voters 5 --num-producers-vote 5 --producer-sync-delay 10


````

#### 0. 清空钱包和多节点进程
````
killall keosd nodeos

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


mkdir -p /Users/tokenfun/mbp_eosio; cd /Users/tokenfun/mbp_eosio

###### A. 清空钱包
rm -rf /Users/tokenfun/mbp_eosio/wallet/; mkdir -p /Users/tokenfun/mbp_eosio/wallet/

###### B. 启动keosd并创建钱包 PW5JKqNbuaCKucg5aSHfHeJZgTXB5DE6LjqeqHK1VxhLGDTFMmYe4
keosd --unlock-timeout 99999999 --http-server-address 127.0.0.1:6666 --wallet-dir /Users/tokenfun/mbp_eosio/wallet/

cleos --wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000 wallet create --to-console
Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5JKqNbuaCKucg5aSHfHeJZgTXB5DE6LjqeqHK1VxhLGDTFMmYe4"

###### B. 导入key
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} wallet import --private-key 5J4PQwZiN6fjTMoZXCgnsqMNw1cvuQ8uDnpJme2JQjs4QXuxExn

cleos ${WALLET_URL} wallet import --private-key 5K73QPaZ7EpCyEPFmadJiaLfF3DD3shugES7ErT33XUVddKrRmW
cleos ${WALLET_URL} wallet import --private-key 5HwnFbF6nqzanQv8Je2aWg8s6isG7hRhYuuqaa3AedVupdKDfPa
cleos ${WALLET_URL} wallet import --private-key 5KRRSgiuaJszYgAE6YhZJhmm77ctTNRzqoZ5R1eU3uRifiXkYEz
cleos ${WALLET_URL} wallet import --private-key 5JFYfjQcYE15Nwcm1UZ1uJovPAWykxmz2w94j5PWsYjjooW5tbQ
cleos ${WALLET_URL} wallet import --private-key 5HuDVKbovz1Nh44BtGqj6bbcLvnZFjn5Y1jVRUbCkb2e9m9pm6d
cleos ${WALLET_URL} wallet import --private-key 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW
cleos ${WALLET_URL} wallet import --private-key 5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy
cleos ${WALLET_URL} wallet import --private-key 5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy
cleos ${WALLET_URL} wallet import --private-key 5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2
cleos ${WALLET_URL} wallet import --private-key 5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2

````

#### 2. 启动eosio创世节点
````
###### A. 清空节点
rm -rf /Users/tokenfun/mbp_eosio/nodes/; mkdir -p /Users/tokenfun/mbp_eosio/nodes/
###### for (( i = 1; i <= 5; i++ )); do for (( j = 1 ; j <=5 ; j++ )); do mkdir ~/eosio_test/accountnum$i$j; done; done

###### A. 启动eosio节点
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-eosio/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-eosio   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-eosio  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8000 --p2p-listen-endpoint 127.0.0.1:9000  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name eosio   --private-key '["EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY","5J4PQwZiN6fjTMoZXCgnsqMNw1cvuQ8uDnpJme2JQjs4QXuxExn"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::history_api_plugin ### --p2p-peer-address localhost:9000

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

export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} wallet unlock --password PW5JKqNbuaCKucg5aSHfHeJZgTXB5DE6LjqeqHK1VxhLGDTFMmYe4

cleos ${WALLET_URL} get account eosio
cleos ${WALLET_URL} create account eosio eosio.bpay EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.msig EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.names EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.ram EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.ramfee EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.saving EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.stake EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.token EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY
cleos ${WALLET_URL} create account eosio eosio.vpay EOS5kxVvnEMKnnW69Cxiseqn9BCu6zweKGkoLGDrX1gxtw3VVasWY


``````

#### 4. 部署eosio.token | eosio.msig 合约

`````
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} set contract eosio.token /Users/tokenfun/eosio/eos/build/contracts/eosio.token
cleos ${WALLET_URL} set contract eosio.msig /Users/tokenfun/eosio/eos/build/contracts/eosio.msig

`````

#### 5. 创建分配 SYS 代币
`````
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} push action eosio.token create '[ "eosio", "10000000000.0000 SYS" ]' -p eosio.token@active
cleos ${WALLET_URL} push action eosio.token issue '[ "eosio", "1000000000.0000 SYS", "memo" ]' -p eosio@active

cleos ${WALLET_URL} get currency stats eosio.token SYS
cleos ${WALLET_URL} get currency balance eosio.token tester
cleos ${WALLET_URL} get currency balance eosio.token eosio
cleos ${WALLET_URL} get table eosio.token SYS stat
cleos ${WALLET_URL} get table eosio.token eosio accounts

`````

#### 6. 部署 eosio.system 系统合约
`````
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} set contract eosio /Users/tokenfun/eosio/eos/build/contracts/eosio.system

问题2: Error 3080006: Transaction took too long
解决2: 重拾一次好了，是不是交易时间有限制呢？

###### 设置eosio.msig为特权帐户

export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} get account eosio.msig
cleos ${WALLET_URL} push action eosio setpriv '["eosio.msig", 1]' -p eosio@active
cleos ${WALLET_URL} get account eosio.msig


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

###### cleos system newaccount eosio --transfer accountnum55 EOS8ZDaRSLPtADQGUsH52XN9wa9kxYi4LqU3bbEQGKoHqGHzsEvBb --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192

export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"

cleos ${WALLET_URL} system newaccount --transfer eosio user11 EOS6XmgJgrftNdhVCJ2ZoyVc2yhz1zeq7UVJy4wDKmqpNjzqpoj9w --stake-net "146382842.7954 SYS" --stake-cpu "146382842.7955 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio user11 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio user12 EOS5CuW8et4tWNusb9qoubddAuhamuH8dARhHQxwf3Hm5z9uy6rz6 --stake-net "146382842.7954 SYS" --stake-cpu "146382842.7955 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio user12 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio user13 EOS8AVyHr1aGPQS2vkCwNoDs8pjAPQNUwKCyjCaw4jzWm9R43gc4S --stake-net "146382842.7954 SYS" --stake-cpu "146382842.7955 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio user13 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio user14 EOS6ko9ajv9ZSzMVoC3qaGASY5f2ir37ftuu5VKxGnJL19nXg4YMu --stake-net "19620199.5302 SYS" --stake-cpu "19620199.5302 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio user14 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio user15 EOS6RTkV6kWTToDKRzNMJctXGy3wGZdSLK5fjBW1YG5i34QdYVwma --stake-net "19620199.5302 SYS" --stake-cpu "19620199.5302  SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio user15 "10.0000 SYS"

cleos ${WALLET_URL} system newaccount --transfer eosio producer11 EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz --stake-net "9810277.0101 SYS" --stake-cpu "9810277.0101 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio producer11 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio producer12 EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55 --stake-net "9810277.0101 SYS" --stake-cpu "9810277.0101 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio producer12 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio producer13 EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt --stake-net "1867182.6445 SYS" --stake-cpu "1867182.6445 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio producer13 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio producer14 EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk --stake-net "81023.1884 SYS" --stake-cpu "81023.1884 SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio producer14 "10.0000 SYS"
cleos ${WALLET_URL} system newaccount --transfer eosio producer15 EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk --stake-net "25536.1884 SYS" --stake-cpu "25536.1884  SYS" --buy-ram "0.1000 SYS"   
cleos ${WALLET_URL} transfer eosio producer15 "10.0000 SYS"


cleos ${WALLET_URL} get currency balance eosio.token user15


问题3: assertion failure with message: overdrawn balance
解决3: 调整平衡理论？不太懂呢

`````

#### 8. 注册生产者producers

`````
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"

cleos ${WALLET_URL} system regproducer producer11 EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz https://producer11.com/EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz
cleos ${WALLET_URL} system regproducer producer12 EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55 https://producer12.com/EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55
cleos ${WALLET_URL} system regproducer producer13 EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt https://producer13.com/EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt
cleos ${WALLET_URL} system regproducer producer14 EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk https://producer14.com/EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk
cleos ${WALLET_URL} system regproducer producer15 EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk https://producer15.com/EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk

###### B. 列出producers
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
cleos ${WALLET_URL} system listproducers

`````

#### 9. 启动producers
`````
producer:
Private key: 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW Public key: EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz
Private key: 5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy Public key: EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55
Private key: 5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy Public key: EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt
Private key: 5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2 Public key: EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk
Private key: 5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2 Public key: EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk


rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer11; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer11
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer11/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer11   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer11  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8001 --p2p-listen-endpoint 127.0.0.1:9001  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer11   --private-key '["EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz","5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000

rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer12; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer12
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer12/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer12   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer12  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8002 --p2p-listen-endpoint 127.0.0.1:9002  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer12   --private-key '["EOS6PE79KUsKKGfbvK3Hv4NwREmG2JXaFWRjKJGx6KqHMLp5PUb55","5JStKAD4QtsJvYszHtJYHKncbX663kMEFyjktqAiQjNVn6hSzSy"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001

rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer13; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer13
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer13/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer13   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer13  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8003 --p2p-listen-endpoint 127.0.0.1:9003  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer13   --private-key '["EOS8WXoYfRF6kN3S59hp23VsETYF3tJkWNp8uxq866cWfqu8T2VLt","5Jxx3RTo5feTt9d779ZGKtB5CiaUp8EDx1aqcxLy2Ete6wFMHNy"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002


rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer14; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer14
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer14/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer14   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer14  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8004 --p2p-listen-endpoint 127.0.0.1:9004  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer14   --private-key '["EOS6wHVUDA1ouZuF3fuJAFP8GenXMM3cEFLivRj8vFjdhGnY3uhhk","5J1kryK5qqh9ePxfpgsHSYJsvUbHtRB4k8ES95YmTgrx3DugWH2"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002 --p2p-peer-address localhost:9003

rm -rf /Users/tokenfun/mbp_eosio/nodes/bp-producer15; mkdir -p /Users/tokenfun/mbp_eosio/nodes/bp-producer15
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json /Users/tokenfun/mbp_eosio/genesis.json --blocks-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer15/blocks --config-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer15   --data-dir /Users/tokenfun/mbp_eosio/nodes/bp-producer15  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8005 --p2p-listen-endpoint 127.0.0.1:9005  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer15   --private-key '["EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk","5JBqqRMvQcgfmZ9XfccX5tAaFkmTJV9E9fsCcyC5cq31CpYvrW2"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002 --p2p-peer-address localhost:9003 --p2p-peer-address localhost:9004


`````

#### 10. 投票producer

`````
export WALLET_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"

cleos ${WALLET_URL} system voteproducer prods user11 producer11 producer12 producer13 
cleos ${WALLET_URL} system voteproducer prods user12 producer11 producer12 producer14 
cleos ${WALLET_URL} system voteproducer prods user13 producer11 producer14 producer13 
cleos ${WALLET_URL} system voteproducer prods user14 producer11 producer12 producer13 
cleos ${WALLET_URL} system voteproducer prods user15 producer14 
cleos ${WALLET_URL} system listproducers


`````

#### 11. 赎回矿工费用
`````

cleos ${WALLET_URL} get table eosio eosio producers -l 100
cleos ${WALLET_URL} system claimrewards -j producer11

`````

#### 12. 代理投票
`````
cleos ${WALLET_URL} system listproducers
cleos ${WALLET_URL} system voteproducer prods producer11 producer12 producer13 producer14 producer15
cleos ${WALLET_URL} system regproxy producer11
cleos ${WALLET_URL} system voteproducer proxy user11 producer11
cleos ${WALLET_URL} system voteproducer proxy user12 producer11
cleos ${WALLET_URL} system voteproducer proxy user13 producer11
cleos ${WALLET_URL} system voteproducer proxy user14 producer11
cleos ${WALLET_URL} system voteproducer proxy user15 producer11

`````

#### 12. Resign eosio
`````

###### 更新 'eosio' => 'eosio.prods'
cleos ${WALLET_URL} get account eosio
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio.prods", "permission": "active"}}]}}' -p eosio@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio.prods", "permission": "active"}}]}}' -p eosio@active
cleos ${WALLET_URL} get account eosio

###### 更新 'eosio.bpay|msig|names|...' => 'eosio'
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.bpay", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.bpay@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.bpay", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.bpay@active
cleos ${WALLET_URL} get account eosio.bpay

cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.msig", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.msig@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.msig", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.msig@active
cleos ${WALLET_URL} get account eosio.msig
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.names", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.names@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.names", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.names@active
cleos ${WALLET_URL} get account eosio.names
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.ram", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ram@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.ram", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ram@active
cleos ${WALLET_URL} get account eosio.ram
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.ramfee", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ramfee@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.ramfee", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.ramfee@active
cleos ${WALLET_URL} get account eosio.ramfee
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.saving", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.saving@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.saving", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.saving@active
cleos ${WALLET_URL} get account eosio.saving
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.stake", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.stake@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.stake", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.stake@active
cleos ${WALLET_URL} get account eosio.stake
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.token", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.token@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.token", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.token@active
cleos ${WALLET_URL} get account eosio.token
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.vpay", "permission": "owner", "parent": "", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.vpay@owner
cleos ${WALLET_URL} push action eosio updateauth '{"account": "eosio.vpay", "permission": "active", "parent": "owner", "auth": {"threshold": 1, "keys": [], "waits": [], "accounts": [{"weight": 1, "permission": {"actor": "eosio", "permission": "active"}}]}}' -p eosio.vpay@active
cleos ${WALLET_URL} get account eosio.vpay


`````

#### 13. Replace system contract using msig
`````

cleos ${WALLET_URL} push action eosio buyrambytes

`````
















