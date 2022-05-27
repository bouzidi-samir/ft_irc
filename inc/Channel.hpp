/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:56:52 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/27 16:30:59 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <map>
#include <vector>
#include "./User.hpp"
#include "./CommandList.hpp"


class Channel {

    private:
            std::string _name;
            std::string _topic;
            std::vector<User*> _memberlist;

    public:
            Channel(std::string name);
            std::string getName() const;
            std::string getTopic() const;
            std::vector<User*> getMemberlist() const;
            void addMember(User *usr);
};


#endif