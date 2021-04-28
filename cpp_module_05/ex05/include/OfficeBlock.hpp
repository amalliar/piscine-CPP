/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:36:22 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/27 04:40:56 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICE_BLOCK_HPP
# define OFFICE_BLOCK_HPP

# include <string>
# include <exception>
# include <cstddef>
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class						OfficeBlock
{
	public:
		void				setIntern(Intern const &rIntern)
								throw (SameObjectRefException, ObjectIsAlreadySetException);
		void				setSigner(Bureaucrat const &rSigner)
								throw (SameObjectRefException, ObjectIsAlreadySetException);
		void				setExecutor(Bureaucrat const &rExecutor)
								throw (SameObjectRefException, ObjectIsAlreadySetException);
		void				unsetIntern(void);
		void				unsetSigner(void);
		void				unsetExecutor(void);

		void				doBureaucracy(std::string const &rFormName, std::string const &rFormTarget)
								throw (InternNotSetException, SignerNotSetException, ExecutorNotSetException,
									SignerGradeTooLowException, ExecutorGradeTooLowException,
									UnknownFormException);

							OfficeBlock(void);
							OfficeBlock(Intern const &rIntern, Bureaucrat const &rSigner, Bureaucrat const &rExecutor);
							~OfficeBlock(void);

		class				InternNotSetException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				SignerNotSetException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				ExecutorNotSetException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				SameObjectRefException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				ObjectIsAlreadySetException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				SignerGradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				ExecutorGradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class				UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Intern const		*_pIntern;
		Bureaucrat const	*_pSigner;
		Bureaucrat const	*_pExecutor;

							OfficeBlock(OfficeBlock const &rSrc);
		OfficeBlock			&operator=(OfficeBlock const &rRhs);
};

#endif // OFFICE_BLOCK_HPP
