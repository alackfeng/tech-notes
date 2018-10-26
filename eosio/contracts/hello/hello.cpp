#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT hello: public contract {
public:
	using contract::contract;

	ACTION hi(name user) {

		require_auth(_self);
		require_auth(user);
		
		print( "hello, ", name{user} );
	}
};

EOSIO_DISPATCH( hello, (hi))
