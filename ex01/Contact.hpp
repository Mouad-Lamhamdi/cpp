/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:17:05 by molamham          #+#    #+#             */
/*   Updated: 2025/11/20 23:32:51 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	private:
		std ::string firstname;
		std ::string lastname;
		std ::string nickname;
		std ::string phonenumber;
		std ::string darkestsecret;

	public:
		void setInfo();//setter
		void showSummary();
		void showDetails();

		//getters
		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getPhonenumber() const;
		std::string getNickname() const;
		std::string getDarkestsecret() const;
};



#endif