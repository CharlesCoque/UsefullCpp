
//Louis Dionne implementation,  Just to help me to remember this technique 

#include <utility>
template<std::size_t S, typename T>
struct Element
{
    using type = T;
};

template<typename S, typename... Ts>
struct Indexer;

template <std::size_t ...Ss, typename ...Ts>
struct Indexer<std::index_sequence<Ss...>, Ts...>
    : Element<Ss, Ts>...
{ };


template<std::size_t S, typename T>
static Element<S,T> select( Element<S, T> );

template<std::size_t S, typename... Ts>
using type = typename decltype (
        select<S>( Indexer< std::index_sequence_for<Ts...>, Ts...>{} )
    )::type;


//The compiler will fail and it will tell us wich type Check was used with
template<typename T>
struct Check;

int main()
{
    Check < type<0, int, float, double> > f;
}
