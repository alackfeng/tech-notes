

## 测试EOSIO合约编码

#### 1. 创建合约账号
`````
cleos ${MBP_URL} wallet unlock --password PW5KXKbVY8oidcMQEPZ2H3T1YQBjSzzzU3zua8mgG6PviwpC2HHNq

cleos ${MBP_URL} create key --to-console
Private key: 5JbuZx3MFvUY1FkYoWdR1o8b4TRCZwQJQzCvrT6JwVdQgLzscVo
Public key: EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv
tokenfundeMBP:mbp_eosio tokenfun$ cleos ${MBP_URL} create key --to-console
Private key: 5J4j8MJdhiHGmJ26CGTHvqMWYeYNMTEL6itTaxXFPAUpPfPm61L
Public key: EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH

cleos ${MBP_URL} wallet import --private-key 5J4j8MJdhiHGmJ26CGTHvqMWYeYNMTEL6itTaxXFPAUpPfPm61L
cleos ${MBP_URL} wallet import --private-key 5JbuZx3MFvUY1FkYoWdR1o8b4TRCZwQJQzCvrT6JwVdQgLzscVo


cleos ${MBP_URL} get account alackfeng521
cleos ${MBP_URL} system newaccount --transfer eosio alackfeng521 EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "0.001 EOS" --stake-cpu "0.001  EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} system newaccount --transfer eosio taurus EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "0.001 EOS" --stake-cpu "0.001  EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} system newaccount --transfer eosio feng EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "0.001 EOS" --stake-cpu "0.001  EOS" --buy-ram "0.1000 EOS"   

cleos ${MBP_URL} system newaccount --transfer taurus token.taurus EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "10.001 EOS" --stake-cpu "10.001  EOS" --buy-ram "11.1000 EOS"   


cleos ${MBP_URL} get accounts EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv

cleos ${MBP_URL} transfer eosio alackfeng521 "1000.0000 EOS"
cleos ${MBP_URL} transfer eosio taurus "1000.0000 EOS"
cleos ${MBP_URL} transfer eosio feng "1000.0000 EOS"


问题1: account taurus has insufficient ram; needs 2996 bytes has 0 bytes
解决1: 不能使用旧接口创建账号：cleos ${MBP_URL} create account

问题2: assertion failure with message: no active bid for name
解决2: 
 
问题3: Exception Details: 3081001 leeway_deadline_exception: Transaction reached the deadline set due to leeway on account CPU limits
解决3: cleos ${MBP_URL} system delegatebw eosio taurus "0 EOS" "10.0000 EOS"

问题4: Exception Details: 3080002 tx_net_usage_exceeded: Transaction exceeded the current network usage limit imposed on the transaction
解决4: cleos ${MBP_URL} system delegatebw eosio taurus "10.0000 EOS" "0.0000 EOS"

问题5: Exception Details: 3080001 ram_usage_exceeded: Account using more than allotted RAM usage
解决5: cleos ${MBP_URL} system buyram eosio dice "100 EOS"

`````

#### 2. 部署测试合约 token.taurus
`````

cleos ${MBP_URL} set contract token.taurus /Users/tokenfun/eosio/eos/build/contracts/eosio.token -p token.taurus@active

cleos ${MBP_URL} get code token.taurus
code hash: 3e0cf4172ab025f9fff5f1db11ee8a34d44779492e1d668ae1dc2d129e865348

cleos ${MBP_URL} push action token.taurus create '[ "eosio", "1000000000.0000 AFT"]' -p token.taurus@active
cleos ${MBP_URL} push action token.taurus create '{"issuer":"taurus", "maximum_supply":"1000000000.0000 AGC"}' -p token.taurus@active
cleos ${MBP_URL} push action token.taurus issue '[ "taurus", "100.0000 AGC", "memo" ]' -p taurus@active
cleos ${MBP_URL} push action token.taurus transfer '[ "taurus", "feng", "25.0000 AGC", "m" ]' -p taurus@active
cleos ${MBP_URL} get currency balance token.taurus taurus

`````

#### 3. 随机数合约 build/contracts/dice
`````bash

##### Create dice account
cleos ${MBP_URL} system newaccount --transfer eosio dice EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "1.001 EOS" --stake-cpu "1.001  EOS" --buy-ram "0.1000 EOS"

##### Set dice contract to dice account
cleos ${MBP_URL} set contract dice /Users/tokenfun/eosio/eos/build/contracts/dice -p dice

##### Create native EOS token
##### Create alice account
cleos ${MBP_URL} system newaccount --transfer eosio alice EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "1.001 EOS" --stake-cpu "1.001  EOS" --buy-ram "0.1000 EOS"
##### Create bob account
cleos ${MBP_URL} system newaccount --transfer eosio bob EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "1.001 EOS" --stake-cpu "1.001  EOS" --buy-ram "0.1000 EOS"

##### Issue 1000 EOS to alice
cleos ${MBP_URL} push action eosio.token issue '[ "alice", "1000.0000 EOS", "" ]' -p eosio
##### Issue 1000 EOS to bob
cleos ${MBP_URL} push action eosio.token issue '[ "bob", "1000.0000 EOS", "" ]' -p eosio

##### Allow dice contract to make transfers on alice behalf (deposit)
cleos ${MBP_URL} set account permission alice active '{"threshold": 1,"keys": [{"key": "EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH","weight": 1}],"accounts": [{"permission":{"actor":"dice","permission":"active"},"weight":1}]}' owner -p alice
##### Allow dice contract to make transfers on bob behalf (deposit)
cleos ${MBP_URL} set account permission bob active '{"threshold": 1,"keys": [{"key": "EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH","weight": 1}],"accounts": [{"permission":{"actor":"dice","permission":"eosio.code"},"weight":1}]}' owner -p bob

##### Alice deposits 100 EOS into the dice contract
cleos ${MBP_URL} push action dice deposit '[ "alice", "100.0000 EOS" ]' -p alice
##### Bob deposits 100 EOS into the dice contract
cleos ${MBP_URL} push action dice deposit '[ "bob", "100.0000 EOS" ]' -p bob

##### Alice generates a secret
openssl rand 32 -hex
ff844d79e0dcbf87b8217dc7cd625b88447d22591dc76430d868f936bb05b887
##### Alice generates sha256(secret)
echo -n 'ff844d79e0dcbf87b8217dc7cd625b88447d22591dc76430d868f936bb05b887' | xxd -r -p | shasum -a 256 -b | awk '{print $1}'
2f3c6d17f310f27979fdedabc6718835a4210a93d7c6d14a18dbe0cb54a7f4a1
##### Alice bets 3 EOS
cleos ${MBP_URL} push action dice offerbet '[ "3.0000 EOS", "alice", "2f3c6d17f310f27979fdedabc6718835a4210a93d7c6d14a18dbe0cb54a7f4a1" ]' -p alice

##### Bob generates a secret
openssl rand 32 -hex
10035c55dbf1ac845948ce2685fe817b6c2a5b36250ae1b9afa24cb084cd89d4
##### Bob generates sha256(secret)
echo -n '10035c55dbf1ac845948ce2685fe817b6c2a5b36250ae1b9afa24cb084cd89d4' | xxd -r -p | shasum -a 256 -b | awk '{print $1}'
de5bf280cc164f91ef75c7f199f7746e20c982160029b7ae80e87fd4dae46ef9
##### Bob also bets 3 EOS (a game is started)
cleos ${MBP_URL} push action dice offerbet '[ "3.0000 EOS", "bob", "de5bf280cc164f91ef75c7f199f7746e20c982160029b7ae80e87fd4dae46ef9" ]' -p bob


##### Dice contract tables right after the game started
cleos ${MBP_URL} get table dice dice account
cleos ${MBP_URL} get table dice dice game

##### Bob reveals his secret
cleos ${MBP_URL} push action dice reveal '[ "de5bf280cc164f91ef75c7f199f7746e20c982160029b7ae80e87fd4dae46ef9", "10035c55dbf1ac845948ce2685fe817b6c2a5b36250ae1b9afa24cb084cd89d4" ]' -p bob

##### Game table after bob revealed (now the game has a deadline for alice to reveal)
cleos ${MBP_URL} get table dice dice game


##### Alice reveals her secret (the winner is determined, the game is removed)
cleos ${MBP_URL} push action dice reveal '[ "2f3c6d17f310f27979fdedabc6718835a4210a93d7c6d14a18dbe0cb54a7f4a1", "ff844d79e0dcbf87b8217dc7cd625b88447d22591dc76430d868f936bb05b887" ]' -p alice

##### Balance of the accounts after game ends
cleos ${MBP_URL} get table dice dice account

##### Alice withdraw from her dice account 103 EOS
cleos ${MBP_URL} push action dice withdraw '[ "alice", "94.0000 EOS" ]' -p alice
##### Balance of alice after withdraw
cleos ${MBP_URL} get currency balance eosio.token alice eos

cleos ${MBP_URL} push action dice claimexpired '[1]' -p dice
cleos ${MBP_URL} push action dice canceloffer '["81ea7a4443457304e216c3ffcc8cc91374eb0458000000000000000000000000"]' -p dice



`````

#### 4. 更新智能合约 build/contracts/dice
`````bash
###### https://developers.eos.io/eosio-cpp/docs/upgrading-the-system-contract

###### 获取当前system合约最后一次快照
cleos ${MBP_URL} get code -c original_system_contract.wast -a original_system_contract.abi eosio
###### Generate the unsigned transaction which upgrades the system contract:
cleos ${MBP_URL} set contract -s -j -d eosio /Users/tokenfun/eosio/eos/build/contracts/eosio.system | tail -n +4 > upgrade_system_contract_trx.json

`````

#### 5. 编写智能合约
`````
mkdir -p /Users/tokenfun/source/tech-notes/eosio/contracts; cd /Users/tokenfun/source/tech-notes/eosio/contracts
mkdir -p hello; cd hello

vi hello.cpp =>>>
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class hello: public contract {
public:
	using contract::contract;

	[[eosio::action]]
	void hi(account_name user) {
		print( "hello, ", name{user} );
	}
};

EOSIO_ABI( hello, (hi))
<<<<<=====

eosio-cpp -o hello.wasm hello.cpp --abigen

cleos ${MBP_URL} system newaccount --transfer taurus hellotestcdt EOS6gqAJiRVNvAsUQdUCVeBmRyLEQ8UgfhUayEjnxv6LMA6sQ4KwH EOS5zuzB7Yve1T6Z8d5xKg1PefbgHRQ55YsWgwDsitr937VGpA1Dv --stake-net "1.001 EOS" --stake-cpu "1.001  EOS" --buy-ram "1.1000 EOS"

cleos ${MBP_URL} get code hellotestcdt
code hash: 0000000000000000000000000000000000000000000000000000000000000000

cleos ${MBP_URL} set contract hellotestcdt /Users/tokenfun/source/tech-notes/eosio/contracts/hello
executed transaction: 5189593c0581acabf3bf4f1139ea736c28b7570853a161b942938e2ba5957623  1440 bytes  586 us

cleos ${MBP_URL} get code hellotestcdt
code hash: 1c3f1726fe585f25dc6308506f4897b9e0d1ce3f3032f9e17693af36587d431
code hash: e19be3dc1e0f32fb6dc745368cadab825baf5c5c4f2160a5512abadc6e44f1c9

cleos ${MBP_URL} push action hellotestcdt hi '["feng"]' -p hellotestcdt
executed transaction: 78cf326fe7d10b50a3475ccaadeebdcbc66706adc18a7f3f9dd8b8bdf040cbab  104 bytes  324 us
#  hellotestcdt <= hellotestcdt::hi             {"user":"feng"}
>> hello, feng
warning: transaction executed locally, but may not be confirmed by the network yet         ]


cleos ${MBP_URL} push action hellotestcdt hi '["taurus"]' -p hellotestcdt -p taurus -j -d


问题5: Error 3040011: The transaction can not be found
解决5: vi config ==> filter-on = *  , 然后 --replay-blockchain



`````















