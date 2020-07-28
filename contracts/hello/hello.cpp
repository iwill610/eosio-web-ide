//include header file bc it contains classes we need to write smart contracts
#include <eosio/eosio.hpp>

//specified namespace so that it we dont have to type "eosio" everytime (in front of user or print?)
using namespace eosio;

//define class hello and inherit from base class called contract (in eosio library)
class [[eosio::contract]] hello : public contract {
 //public access specifier, since its going to be a public function    
    public:
        //using declaration 
        using contract::contract;
        
        //add anotation here @ top of funct, it tells the abi generator to see which functs are actions that exist in the contract
        /* essentially it is letting the abi generator know that this funct is not just a c++ funct, its actually actually an eosio action
            an action is a funct that we can call from outside to execute the "hi" funct */
        [[eosio::action]]
        
        //function called hi, which takes one argument, which is type "name" (one of the eosio titles)
        void hi( name user ) {
            //makes it so you can only send messages to accounts that exist
            require_auth( user );
            //print hello folled by name under the console
            print( "Hello, ", user);
        }
};