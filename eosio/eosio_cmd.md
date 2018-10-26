



#### 
`````

cleos ${MBP_URL} get scope eosio

###### cpu net

cleos ${MBP_URL} get table eosio user21 userres
cleos ${MBP_URL} get table eosio user21 delband
cleos ${MBP_URL} get table eosio user21 refunds

###### cpu net market ...
cleos ${MBP_URL} get table eosio eosio rammarket

###### system parameter state ...
cleos ${MBP_URL} get table eosio eosio global



###### eosio.token
cleos ${MBP_URL} get table eosio.token EOS stat
cleos ${MBP_URL} get table eosio.token eosio accounts

cleos ${MBP_URL} get scope eosio.token

###### currency balance
cleos ${MBP_URL} get currency stats eosio.token EOS
cleos ${MBP_URL} get currency balance eosio.token taurus
cleos ${MBP_URL} get currency balance eosio.token eosio

###### bp info
cleos ${MBP_URL} get table eosio eosio producers
cleos ${MBP_URL} get table eosio eosio voters


###### bidname service
cleos ${MBP_URL} system bidname eosio alack "0.001 EOS"
cleos ${MBP_URL} system bidnameinfo alack
cleos ${MBP_URL} get table eosio eosio namebids

cleos ${MBP_URL} system newaccount --transfer eosio alack EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk --stake-net "1000.1884 EOS" --stake-cpu "1000.1884  EOS" --buy-ram "0.1000 EOS"   
cleos ${MBP_URL} system newaccount --transfer alack a.alack EOS65erFADQsFxiCUQmLyrWhVTinGowXmcgRhTDf6J6tKfGzqrBCk --stake-net "1000.1884 EOS" --stake-cpu "1000.1884  EOS" --buy-ram "0.1000 EOS"   


###### rpc command
###### https://developers.eos.io/eosio-nodeos/reference#get_info

curl --request POST   --url http://127.0.0.1:8000/v1/chain/get_block -d '{"block_num_or_id":5}' | jq
curl --request POST   --url http://127.0.0.1:8000/v1/chain/get_abi -d '{"account_name": "eosio"}' | jq
curl  http://127.0.0.1:8000/v1/chain/get_table_rows -X POST -d '{"scope":"eosio", "code":"eosio.token", "table":"accounts", "json": true}' | jq
curl  http://127.0.0.1:8000/v1/chain/get_table_rows -X POST -d '{"scope":"eosio", "code":"eosio.token", "table":"accounts", "json": true, "lower_bound":0, "upper_bound":-1, "limit":10}' | jq

`````