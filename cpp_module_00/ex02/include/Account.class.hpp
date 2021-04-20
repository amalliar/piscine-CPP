// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class					Account
{
	public:
		typedef Account	t;

		void			displayStatus( void ) const;
		void			makeDeposit( int deposit );
		bool			makeWithdrawal( int withdrawal );
		int				checkAmount( void ) const;
		int				getNbCheckAmountCalls( void ) const;

						Account( int initial_deposit );
						~Account( void );

		static void		displayAccountsInfos( void );
		static int		getNbAccounts( void );
		static int		getNbDeposits( void );
		static int		getNbWithdrawals( void );
		static int		getTotalAmount( void );

	private:
		int				_accountIndex;
		int				_amount;
		int				_nbDeposits;
		int				_nbWithdrawals;
		int				_nbCheckAmountCalls;

		static int		_nbAccounts;
		static int		_totalAmount;
		static int		_totalNbDeposits;
		static int		_totalNbWithdrawals;

		static void		_displayTimestamp( void );

						Account( void );
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
