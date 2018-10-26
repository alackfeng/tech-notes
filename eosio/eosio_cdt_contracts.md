

## 测试eosio两个新工程：eosio.cdt | eosio.contracts

#### 


`````bash

cleos ${MBP_URL} get code eosio.token
code hash: 3e0cf4172ab025f9fff5f1db11ee8a34d44779492e1d668ae1dc2d129e865348
cleos ${MBP_URL} get currency balance eosio.token taurus
968.6940 EOS
cleos ${MBP_URL} get table eosio.token EOS stat
{
  "rows": [{
      "supply": "1000002000.0000 EOS",
      "max_supply": "10000000000.0000 EOS",
      "issuer": "eosio"
    }
  ],
  "more": false
}

cleos ${MBP_URL} set contract eosio.token /Users/tokenfun/eosio/eosio.contracts/build/eosio.token
executed transaction: 7b205bfa20b82aff0901db778b3df29aad3fec4194e42d35132fac1e6230411b  9744 bytes  8201 us

cleos ${MBP_URL} get code eosio.token
code hash: 32f981cb7a5a690269d59d41312a96882e82405cf5755965fccb9863a1b28cb7
cleos ${MBP_URL} get currency balance eosio.token taurus
968.6940 EOS
cleos ${MBP_URL} get table eosio.token EOS stat
{
  "rows": [{
      "supply": "1000002000.0000 EOS",
      "max_supply": "10000000000.0000 EOS",
      "issuer": "eosio"
    }
  ],
  "more": false
}


cleos ${MBP_URL} push action eosio.token create '[ "taurus", "10000000000.0000 AFT" ]' -p eosio.token@active
cleos ${MBP_URL} push action eosio.token issue '[ "taurus", "1000000000.0000 AFT", "memo" ]' -p taurus@active
cleos ${MBP_URL} get currency balance eosio.token taurus


`````