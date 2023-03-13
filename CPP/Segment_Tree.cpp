//
// Created by Bhavy on 13-03-2023.
//
#include <bits/stdc++.h>
using namespace std;


template <class T>
class Segment_Tree
	{
	public:
		int len ;
		const T def_value = (int) 2e9+53   ;
		vector < T > arr , lazy , seg_tree ;
		
		/*
		 * CURRENT DEFAULT OPERATION IS  MIN( A , B )
		 */
		T Operation ( T a , T b )
			{
				if ( a == -1 ) return b ;
				if ( b == -1 ) return a ;
				return min( a, b );
			}
		
		int left_node (T node)
			{
				return node << 1;
			}
		int right_node ( T node)
			{
				return ( node << 1 ) + 1 ;
			}
		void build ( int node , int L, int R)
			{
				if ( L == R )
					seg_tree [ node ] = arr[ L ];
				else
					{
						int m = L + ( R - L ) / 2;
						build ( left_node ( node ) , L , m  );
						build( right_node ( node ) , m + 1 , R );
						seg_tree[ node ] = Operation ( seg_tree[ left_node ( node ) ]  ,  seg_tree [ right_node ( node )] );
					}
			}
		void propagate ( int node , int L , int R )
			{
				if( lazy[ node ] != -1 )
					{
						seg_tree[ node ] = lazy[ node ]; // if it has a lazy flag then it'd mean [ l..r ]  has same value.
						if ( L != R )
							{
								lazy [ left_node ( node ) ] = lazy [ right_node ( node ) ] = lazy [ node ];
							}
						else  // L == R
							{
								arr[ L ] = lazy[ node ];
							}
						lazy [ node ] = -1 ; // done with lazy flag , can now remove this.
					}
			}
			
		T query ( int node , int L , int R , int i , int j )
			{
				propagate ( node , L , R );
				if ( i > j ) return -1;
				if ( (L >= i ) and ( R <= j ) )
					{
						return seg_tree [ node ];
					}
				int m = L + ( R - L ) / 2 ;
				return Operation (
				 query (	left_node ( node ) , L , m , i, min( m,j)  )   ,
				 query ( right_node ( node ) , m + 1 , R , max( i , m + 1 ) , j )
				 );
			}
			
		void update ( int node , int L , int R , int i , int j , T val )
			{
				propagate ( node , L , R );
				if ( i > j )return ;
				
				if( (L >= i ) and  ( R <= j) )
					{
						lazy [ node ] = val ;
						propagate ( node , L , R );
					}
				else
					{
						int m =  L +  ( R - L ) / 2;
						update ( left_node ( node ) , L , m , i , min( m,j) , val);
						update ( right_node ( node ) , m+ 1 , R , max( i , m +1 ) , j , val );
						
						int ltree =  ( lazy [ left_node ( node ) ] != -1 ) ? lazy [ left_node ( node ) ] : seg_tree [ left_node ( node ) ];
						int rtree =  ( lazy [ right_node ( node ) ] != -1 ) ?  lazy[ right_node ( node ) ] : seg_tree [ right_node ( node )];
						
						seg_tree[ node ] = ( ltree <= rtree ) ? seg_tree [ left_node ( node ) ] : seg_tree [ right_node ( node ) ];
					}
			}
			
		Segment_Tree ( int sz ) : len( sz ) , seg_tree ( 4 * sz ) , lazy( 4*sz , -1 ) {}
		
		Segment_Tree( const vector < T > &init_arr ) : Segment_Tree ( (int) init_arr.size() )
			{
				arr = init_arr;
				build ( 1, 0  , len - 1 );
			}
			
			
		/*
		 * for user
		 */
		
		void update ( int i , int  j , T val )
			{
				update( 1 ,  0 , len-1 , i , j , val );
			}
		
		T query ( int i , int j )
			{
				return query ( 1, 0 , len - 1 , i, j );
			}
	};

