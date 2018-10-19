

## eos构建系统启动顺序(BIOS Boot Sequence - ubuntu)

#### 参考链接
``````
###### https://developers.eos.io/eosio-nodeos/docs/bios-boot-sequence
###### /Users/tokenfun/eosio/eos/tutorials/bios-boot-tutorial/bios-boot-tutorial.py
``````
#### 环境 

`````
OS: 		ubuntu 16.04 LTS
CODE: 		git branch - master - commit 8f0f54c
VERSION: 	v1.3.1-dirty


`````
#### 清空相关数据
````
killall keosd nodeos

export MBP_DIR=/data/blockeosio/mbp_chain; 
export MBP_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"

sudo mkdir -p ${MBP_DIR}; cd ${MBP_DIR};
sudo chown -R vagrant:vagrant /data

rm -r ~/.local/share/eosio/
rm -r ~/eosio-wallet/

````

#### 自动化测试脚步pythons
````
Ubuntu1604：python3

pip3 install numpy   #### pip install numpy

cd /home/vagrant/eosio/eos/tutorials/bios-boot-tutorial
./bios-boot-tutorial.py -a --producer-limit 5 --user-limit 5 --num-voters 3 --num-producers-vote 3 --producer-sync-delay 10


````

#### 0. 清空钱包和多节点进程
````
killall keosd nodeos
sudo rm -rf ${MBP_DIR}/wallet/
sudo rm -rf ${MBP_DIR}/nodes/
sudo rm -rf ${MBP_DIR}

````

#### 1. 启动钱包keosd
````
###### 私钥KEY准备
for (( i = 1; i <= 11; i++ )); do cleos create key --to-console | xargs; done
eosio -
Private key: 5KK4ZoGiAcR5gBuFPwFdNodtTWDZeEFTVAXixcgFFnNzmyJKs8E Public key: EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
users -
Private key: 5JM5p5iy2VAbYfDRLwhL4xuxnDZyxvZixYdvJg8tGKKLGrbY8Gp Public key: EOS6w226fMQyunGQe2waJQVWM6WtyPaJu5qJY7eqjFWARttvUpWz6
Private key: 5J3GHGyU3vQpN926TovrBR6aymKNbUkWcRXEi7ofB2Rsum1jrDC Public key: EOS8kXyeR7YiPYdAVvjqaczPEraNy21KVEspUVwE14nBpuHDdzsmD
Private key: 5JdR2sjXEY5WAKkAs7QDGtvv39xxvUnbfXNgXeK2e7MQrF2aDim Public key: EOS7nKtHm3qPTZLSgzM9LDHQRpb21tvdAZZJKzG5nBP1usVXKFDtM
Private key: 5KL43t5hD9J7sNV6eBCrvXoW2DuDXWLUV8Lw9ANV59kSgt6CSS5 Public key: EOS7xzF9413DcngKq994iWbMEFUr2EFN26AWwsNyfSVtBppGHHcGU
Private key: 5Jetnejgv7dxFmzaszcnK52rm2WzCRsrXo1hrMMPQamgbc5XEef Public key: EOS6ozp4rTyc13X2f4nmyoyeiCijeugnK5fWvgAeijBTsyd7Yhhy3
producers -
Private key: 5JwWDEEdBKLiRJeFDbG3sb6WpTNvCWmJKdPUxnFL2uH3TaoTX47 Public key: EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN
Private key: 5JcR8gyyTJgRtdHkKme5DxBf7Ro2n7LMfZ82iQzj8ZrWQZVRqnv Public key: EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya
Private key: 5HvBnW2Xcu8L8ARLGd9ouKX7fpbijxhX51xTyg2adBPrjEGkNvD Public key: EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd
Private key: 5JghLNk5Yd2ztJ1DJppwcgXbXGAj6fc5qsrRggcBHMjVJ5JwqHF Public key: EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo
Private key: 5KHfm1GrUury7JFuBRm7LCgY2oHE9sGPuJtEfmE1sN1nJGoqPwn Public key: EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g

###### export MBP_DIR=/Users/tokenfun/mbp_eosio; 
###### export MBP_URL="--wallet-url http://127.0.0.1:6666 --url http://127.0.0.1:8000"
###### sudo mkdir -p ${MBP_DIR}; cd ${MBP_DIR};

###### A. 清空钱包
export MBP_DIR=/data/blockeosio/mbp_chain; rm -rf ${MBP_DIR}/wallet/; mkdir -p ${MBP_DIR}/wallet/

###### B. 启动keosd并创建钱包 PW5K3eyHJ11gjvBiX2TLLrbmef3G3M8AqmMzpwf3veyvVzuaof81K
nohup keosd --unlock-timeout 99999999 --http-server-address 127.0.0.1:6666 --wallet-dir ${MBP_DIR}/wallet/ 2>&1 >> ${MBP_DIR}/wallet/stderr &

cleos ${MBP_URL} wallet create --file password-wallet.txt
cleos ${MBP_URL} wallet create --to-console
Creating wallet: default
Save password to use in the future to unlock this wallet.
Without password imported keys will not be retrievable.
"PW5K3eyHJ11gjvBiX2TLLrbmef3G3M8AqmMzpwf3veyvVzuaof81K"

###### C. 导入key

cleos ${MBP_URL} wallet import --private-key 5KK4ZoGiAcR5gBuFPwFdNodtTWDZeEFTVAXixcgFFnNzmyJKs8E

cleos ${MBP_URL} wallet import --private-key 5JM5p5iy2VAbYfDRLwhL4xuxnDZyxvZixYdvJg8tGKKLGrbY8Gp
cleos ${MBP_URL} wallet import --private-key 5J3GHGyU3vQpN926TovrBR6aymKNbUkWcRXEi7ofB2Rsum1jrDC
cleos ${MBP_URL} wallet import --private-key 5JdR2sjXEY5WAKkAs7QDGtvv39xxvUnbfXNgXeK2e7MQrF2aDim
cleos ${MBP_URL} wallet import --private-key 5KL43t5hD9J7sNV6eBCrvXoW2DuDXWLUV8Lw9ANV59kSgt6CSS5
cleos ${MBP_URL} wallet import --private-key 5Jetnejgv7dxFmzaszcnK52rm2WzCRsrXo1hrMMPQamgbc5XEef

cleos ${MBP_URL} wallet import --private-key 5JwWDEEdBKLiRJeFDbG3sb6WpTNvCWmJKdPUxnFL2uH3TaoTX47
cleos ${MBP_URL} wallet import --private-key 5JcR8gyyTJgRtdHkKme5DxBf7Ro2n7LMfZ82iQzj8ZrWQZVRqnv
cleos ${MBP_URL} wallet import --private-key 5HvBnW2Xcu8L8ARLGd9ouKX7fpbijxhX51xTyg2adBPrjEGkNvD
cleos ${MBP_URL} wallet import --private-key 5JghLNk5Yd2ztJ1DJppwcgXbXGAj6fc5qsrRggcBHMjVJ5JwqHF
cleos ${MBP_URL} wallet import --private-key 5KHfm1GrUury7JFuBRm7LCgY2oHE9sGPuJtEfmE1sN1nJGoqPwn

````

#### 2. 启动eosio创世节点
````
###### A. 清空节点
rm -rf ${MBP_DIR}/nodes/; mkdir -p ${MBP_DIR}/nodes/
###### for (( i = 1; i <= 5; i++ )); do for (( j = 1 ; j <=5 ; j++ )); do mkdir ~/eosio_test/accountnum$i$j; done; done

###### A. 启动eosio节点
rm -rf ${MBP_DIR}/nodes/bp-eosio; mkdir -p ${MBP_DIR}/nodes/bp-eosio
nohup nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-eosio/blocks --config-dir ${MBP_DIR}/nodes/bp-eosio   --data-dir ${MBP_DIR}/nodes/bp-eosio  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8000 --p2p-listen-endpoint 0.0.0.0:9000  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name eosio   --private-key '["EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i","5KK4ZoGiAcR5gBuFPwFdNodtTWDZeEFTVAXixcgFFnNzmyJKs8E"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::history_api_plugin 2>&1 >> ${MBP_DIR}/nodes/bp-eosio/stderr &

nohup nodeos --config-dir ${MBP_DIR}/nodes/bp-eosio  --data-dir ${MBP_DIR}/nodes/bp-eosio  --http-server-address 127.0.0.1:8000 --p2p-listen-endpoint 0.0.0.0:9000  --enable-stale-production --producer-name eosio 2>&1 >> ${MBP_DIR}/nodes/bp-eosio/stderr &

````

#### 3. 创建重要的系统账号
`````
######  eosio.bpay
######  eosio.msig
######  eosio.names
######  eosio.ram
######  eosio.ramfee
######  eosio.saving
######  eosio.stake
######  eosio.token
######  eosio.vpay




cleos ${MBP_URL} wallet unlock --password PW5K3eyHJ11gjvBiX2TLLrbmef3G3M8AqmMzpwf3veyvVzuaof81K

cleos ${MBP_URL} get account eosio
cleos ${MBP_URL} create account eosio eosio.bpay EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i -j -d
cleos ${MBP_URL} create account eosio eosio.bpay EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.msig EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.names EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.ram EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.ramfee EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.saving EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.stake EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.token EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio eosio.vpay EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i
cleos ${MBP_URL} create account eosio taurus EOS6wAwsSJh3GzUHgeadRRBFcm78zTXyciEQoib7wd8k8HBWYAR8i


`````

#### 4. 部署eosio.token | eosio.msig 合约

`````

cleos ${MBP_URL} set contract eosio.token /home/vagrant/eosio/eos/build/contracts/eosio.token
cleos ${MBP_URL} set contract eosio.msig /home/vagrant/eosio/eos/build/contracts/eosio.msig

`````

#### 5. 创建分配 EOS 代币
`````

cleos ${MBP_URL} push action eosio.token create '[ "eosio", "10000000000.0000 EOS" ]' -p eosio.token@active
cleos ${MBP_URL} push action eosio.token issue '[ "eosio", "1000000000.0000 EOS", "memo" ]' -p eosio@active
cleos ${MBP_URL} push action eosio.token issue '[ "taurus", "1000000000.0000 EOS", "memo" ]' -p eosio@active

cleos ${MBP_URL} push action eosio.token create '[ "taurus", "10000000000.0000 SYS" ]' -p eosio.token@active
cleos ${MBP_URL} push action eosio.token issue '[ "eosio", "1000000000.0000 SYS", "memo" ]' -p taurus@active
cleos ${MBP_URL} push action eosio.token issue '[ "taurus", "1000000000.0000 SYS", "memo" ]' -p taurus@active


cleos ${MBP_URL} get currency stats eosio.token EOS
cleos ${MBP_URL} get currency balance eosio.token taurus
cleos ${MBP_URL} get currency balance eosio.token eosio
cleos ${MBP_URL} get table eosio.token EOS stat
cleos ${MBP_URL} get table eosio.token eosio accounts

`````

#### 6. 部署 eosio.system 系统合约
`````

cleos ${MBP_URL} set contract eosio /home/vagrant/eosio/eos/build/contracts/eosio.system

问题2: Error 3080006: Transaction took too long
解决2: 重拾一次好了，是不是交易时间有限制呢？

###### 设置eosio.msig为特权帐户

cleos ${MBP_URL} get account eosio.msig
cleos ${MBP_URL} push action eosio setpriv '["eosio.msig", 1]' -p eosio@active
cleos ${MBP_URL} get account eosio.msig
###### privileged: true

`````

#### 7. 创建Staked抵押账户

`````
users -
Private key: 5JM5p5iy2VAbYfDRLwhL4xuxnDZyxvZixYdvJg8tGKKLGrbY8Gp Public key: EOS6w226fMQyunGQe2waJQVWM6WtyPaJu5qJY7eqjFWARttvUpWz6
Private key: 5J3GHGyU3vQpN926TovrBR6aymKNbUkWcRXEi7ofB2Rsum1jrDC Public key: EOS8kXyeR7YiPYdAVvjqaczPEraNy21KVEspUVwE14nBpuHDdzsmD
Private key: 5JdR2sjXEY5WAKkAs7QDGtvv39xxvUnbfXNgXeK2e7MQrF2aDim Public key: EOS7nKtHm3qPTZLSgzM9LDHQRpb21tvdAZZJKzG5nBP1usVXKFDtM
Private key: 5KL43t5hD9J7sNV6eBCrvXoW2DuDXWLUV8Lw9ANV59kSgt6CSS5 Public key: EOS7xzF9413DcngKq994iWbMEFUr2EFN26AWwsNyfSVtBppGHHcGU
Private key: 5Jetnejgv7dxFmzaszcnK52rm2WzCRsrXo1hrMMPQamgbc5XEef Public key: EOS6ozp4rTyc13X2f4nmyoyeiCijeugnK5fWvgAeijBTsyd7Yhhy3
producers -
Private key: 5JwWDEEdBKLiRJeFDbG3sb6WpTNvCWmJKdPUxnFL2uH3TaoTX47 Public key: EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN
Private key: 5JcR8gyyTJgRtdHkKme5DxBf7Ro2n7LMfZ82iQzj8ZrWQZVRqnv Public key: EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya
Private key: 5HvBnW2Xcu8L8ARLGd9ouKX7fpbijxhX51xTyg2adBPrjEGkNvD Public key: EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd
Private key: 5JghLNk5Yd2ztJ1DJppwcgXbXGAj6fc5qsrRggcBHMjVJ5JwqHF Public key: EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo
Private key: 5KHfm1GrUury7JFuBRm7LCgY2oHE9sGPuJtEfmE1sN1nJGoqPwn Public key: EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g

###### cleos ${MBP_URL} system newaccount eosio --transfer accountnum55 EOS6w226fMQyunGQe2waJQVWM6WtyPaJu5qJY7eqjFWARttvUpWz6 --stake-net "100000.0000 SYS" --stake-cpu "100000.0000 SYS" --buy-ram-kbytes 8192


cleos ${MBP_URL} system newaccount --transfer eosio user11 EOS6w226fMQyunGQe2waJQVWM6WtyPaJu5qJY7eqjFWARttvUpWz6 --stake-net "146382842.7954 SYS" --stake-cpu "146382842.7955 SYS" --buy-ram "0.1000 SYS"   
cleos ${MBP_URL} transfer eosio user11 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user12 EOS8kXyeR7YiPYdAVvjqaczPEraNy21KVEspUVwE14nBpuHDdzsmD --stake-net "124427166.9055 EOS" --stake-cpu "124427166.9055 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user12 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user13 EOS7nKtHm3qPTZLSgzM9LDHQRpb21tvdAZZJKzG5nBP1usVXKFDtM --stake-net "54250159.9678 EOS" --stake-cpu "54250159.9678 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user13 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user14 EOS7xzF9413DcngKq994iWbMEFUr2EFN26AWwsNyfSVtBppGHHcGU --stake-net "29543656.6440 EOS" --stake-cpu "29543656.6440 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user14 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio user15 EOS6ozp4rTyc13X2f4nmyoyeiCijeugnK5fWvgAeijBTsyd7Yhhy3 --stake-net "20703368.5118 EOS" --stake-cpu "20703368.5118  EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio user15 "10.0000 EOS"

cleos ${MBP_URL} system newaccount --transfer eosio producer11 EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN --stake-net "9810277.0101 EOS" --stake-cpu "9810277.0101 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer11 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer12 EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya --stake-net "8678719.3894 EOS" --stake-cpu "8678719.3894 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer12 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer13 EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd --stake-net "8295536.1884 EOS" --stake-cpu "8295536.1884 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer13 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer14 EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo --stake-net "6636248.7910 EOS" --stake-cpu "6636248.7910 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer eosio producer14 "10.0000 EOS"
cleos ${MBP_URL} system newaccount --transfer eosio producer15 EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g --stake-net "5867182.6445 SYS" --stake-cpu "5867182.6445  SYS" --buy-ram "0.1000 SYS"   
cleos ${MBP_URL} transfer eosio producer15 "10.0000 EOS"


cleos ${MBP_URL} get currency balance eosio.token user15


问题3: assertion failure with message: overdrawn balance
解决3: 调整平衡理论？不太懂呢

`````

#### 8. 注册生产者producers

`````

cleos ${MBP_URL} system regproducer producer11 EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN https://producer11.com/EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN
cleos ${MBP_URL} system regproducer producer12 EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya https://producer12.com/EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya
cleos ${MBP_URL} system regproducer producer13 EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd https://producer13.com/EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd
cleos ${MBP_URL} system regproducer producer14 EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo https://producer14.com/EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo
cleos ${MBP_URL} system regproducer producer15 EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g https://producer15.com/EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g

###### B. 列出producers
cleos ${MBP_URL} system listproducers

`````

#### 9. 启动producers
`````
producers -
Private key: 5JwWDEEdBKLiRJeFDbG3sb6WpTNvCWmJKdPUxnFL2uH3TaoTX47 Public key: EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN
Private key: 5JcR8gyyTJgRtdHkKme5DxBf7Ro2n7LMfZ82iQzj8ZrWQZVRqnv Public key: EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya
Private key: 5HvBnW2Xcu8L8ARLGd9ouKX7fpbijxhX51xTyg2adBPrjEGkNvD Public key: EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd
Private key: 5JghLNk5Yd2ztJ1DJppwcgXbXGAj6fc5qsrRggcBHMjVJ5JwqHF Public key: EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo
Private key: 5KHfm1GrUury7JFuBRm7LCgY2oHE9sGPuJtEfmE1sN1nJGoqPwn Public key: EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g


sudo rm -rf ${MBP_DIR}/nodes/bp-producer11; sudo mkdir -p ${MBP_DIR}/nodes/bp-producer11
sudo nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-producer11/blocks --config-dir ${MBP_DIR}/nodes/bp-producer11   --data-dir ${MBP_DIR}/nodes/bp-producer11  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8001 --p2p-listen-endpoint 127.0.0.1:9001  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer11   --private-key '["EOS5JgWbwM5wqiduEZW6Afg5h7msJiLJdFsVmawMDCmSAXeQ3H8EN","5JwWDEEdBKLiRJeFDbG3sb6WpTNvCWmJKdPUxnFL2uH3TaoTX47"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000

sudo rm -rf ${MBP_DIR}/nodes/bp-producer12; sudo mkdir -p ${MBP_DIR}/nodes/bp-producer12
sudo nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-producer12/blocks --config-dir ${MBP_DIR}/nodes/bp-producer12   --data-dir ${MBP_DIR}/nodes/bp-producer12  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8002 --p2p-listen-endpoint 127.0.0.1:9002  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer12   --private-key '["EOS4zjsBHYm5cYFcpvoLuL6wDMioPwgbmFyR9GhBk9mm1wNrsmFya","5JcR8gyyTJgRtdHkKme5DxBf7Ro2n7LMfZ82iQzj8ZrWQZVRqnv"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001

sudo rm -rf ${MBP_DIR}/nodes/bp-producer13; sudo mkdir -p ${MBP_DIR}/nodes/bp-producer13
sudo nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-producer13/blocks --config-dir ${MBP_DIR}/nodes/bp-producer13   --data-dir ${MBP_DIR}/nodes/bp-producer13  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8003 --p2p-listen-endpoint 127.0.0.1:9003  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer13   --private-key '["EOS7YeF9NgtnsSvby6dWbWhrzaJTegEHgYiUZpfaZ4qxB34V4FFhd","5HvBnW2Xcu8L8ARLGd9ouKX7fpbijxhX51xTyg2adBPrjEGkNvD"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002

sudo rm -rf ${MBP_DIR}/nodes/bp-producer14; sudo mkdir -p ${MBP_DIR}/nodes/bp-producer14
sudo nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-producer14/blocks --config-dir ${MBP_DIR}/nodes/bp-producer14   --data-dir ${MBP_DIR}/nodes/bp-producer14  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8004 --p2p-listen-endpoint 127.0.0.1:9004  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer14   --private-key '["EOS5hM7eZNQP8YSyXcCeN6rjP2J4rW3NFbC5h5yF8m15vRLkmMsFo","5JghLNk5Yd2ztJ1DJppwcgXbXGAj6fc5qsrRggcBHMjVJ5JwqHF"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002 --p2p-peer-address localhost:9003

sudo rm -rf ${MBP_DIR}/nodes/bp-producer15; sudo mkdir -p ${MBP_DIR}/nodes/bp-producer15
sudo nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-producer15/blocks --config-dir ${MBP_DIR}/nodes/bp-producer15   --data-dir ${MBP_DIR}/nodes/bp-producer15  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8005 --p2p-listen-endpoint 127.0.0.1:9005  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name producer15   --private-key '["EOS6ATEGZY5FdsS3hjKY6XPvLm2P5cfz7qgMQahLqtcAGNDmR5x2g","5KHfm1GrUury7JFuBRm7LCgY2oHE9sGPuJtEfmE1sN1nJGoqPwn"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_api_plugin --p2p-peer-address localhost:9000 --p2p-peer-address localhost:9001 --p2p-peer-address localhost:9002 --p2p-peer-address localhost:9003 --p2p-peer-address localhost:9004


`````

#### 10. 投票producer

`````

cleos ${MBP_URL} system voteproducer prods user11 producer11 producer12 producer13 
cleos ${MBP_URL} system voteproducer prods user12 producer11 producer12 producer14 
cleos ${MBP_URL} system voteproducer prods user13 producer11 producer14 producer13 
cleos ${MBP_URL} system voteproducer prods user14 producer11 producer12 producer13 
cleos ${MBP_URL} system voteproducer prods user15 producer14 
cleos ${MBP_URL} system listproducers


`````

#### 11. 赎回矿工费用
`````

cleos ${MBP_URL} get table eosio eosio producers -l 100
cleos ${MBP_URL} system claimrewards -j producer11

`````

#### 12. 代理投票
`````
cleos ${MBP_URL} system listproducers
cleos ${MBP_URL} system voteproducer prods producer11 producer12 producer13 producer14 producer15
cleos ${MBP_URL} system regproxy producer11
cleos ${MBP_URL} system voteproducer proxy user11 producer11
cleos ${MBP_URL} system voteproducer proxy user12 producer11
cleos ${MBP_URL} system voteproducer proxy user13 producer11
cleos ${MBP_URL} system voteproducer proxy user14 producer11
cleos ${MBP_URL} system voteproducer proxy user15 producer11

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

#### 13. 使用多重签名替换system合约
`````

cleos ${MBP_URL} push action eosio buyrambytes '["eosio", "user11", 200000]' -p eosio

问题4: assertion failure with message: no balance object found
解决4: 

`````



#### 14. 跨机器单独申请节点
###### ====== user21 account =========
````

Private key: 5K73QPaZ7EpCyEPFmadJiaLfF3DD3shugES7ErT33XUVddKrRmW Public key: EOS6XmgJgrftNdhVCJ2ZoyVc2yhz1zeq7UVJy4wDKmqpNjzqpoj9w

cleos ${MBP_URL} wallet import --private-key 5K73QPaZ7EpCyEPFmadJiaLfF3DD3shugES7ErT33XUVddKrRmW
cleos ${MBP_URL} system newaccount --transfer eosio user21 EOS6XmgJgrftNdhVCJ2ZoyVc2yhz1zeq7UVJy4wDKmqpNjzqpoj9w --stake-net "82842.7954 EOS" --stake-cpu "82842.7955 EOS" --buy-ram "0.1000 EOS"   

cleos ${MBP_URL} transfer eosio user21 "10000.0000 EOS"

````


###### ====== alackfeng521 producer =========
````
Private key: 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW Public key: EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz

cleos ${MBP_URL} wallet import --private-key 5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW
cleos ${MBP_URL} system newaccount --transfer user21 alackfeng521 EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz --stake-net "1277.0101 EOS" --stake-cpu "1277.0101 EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} transfer user21 alackfeng521 "10.0000 EOS"
cleos ${MBP_URL} system regproducer alackfeng521 EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz https://alackfeng521.com/EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz

cleos ${MBP_URL} system voteproducer prods user21 alackfeng521
cleos ${MBP_URL} system voteproducer prods user15 alackfeng521
cleos ${MBP_URL} system voteproducer prods user14 alackfeng521

问题1: assertion failure with message: no active bid for name
解决1: 

rm -rf ${MBP_DIR}/nodes/bp-alackfeng521; mkdir -p ${MBP_DIR}/nodes/bp-alackfeng521
nodeos --max-irreversible-block-age -1 --contracts-console --genesis-json ${MBP_DIR}/genesis.json --blocks-dir ${MBP_DIR}/nodes/bp-alackfeng521/blocks --config-dir ${MBP_DIR}/nodes/bp-alackfeng521   --data-dir ${MBP_DIR}/nodes/bp-alackfeng521  --chain-state-db-size-mb 1024 --http-server-address 127.0.0.1:8000 --p2p-listen-endpoint 0.0.0.0:9000  --max-clients 25   --p2p-max-nodes-per-host 25  --enable-stale-production --producer-name alackfeng521   --private-key '["EOS7ZtdL3zpPvAaGjVkytno7LBPzNK8W5p7XURvRbaG1uC6d7Q4Lz","5Jm3kYjqMycqThnhmsXmxtTkmXkk7sC8T1NZFBedyCx1wiksoKW"]' --plugin eosio::http_plugin --plugin eosio::chain_api_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::history_api_plugin --p2p-peer-address 192.168.1.87:9000

````

















