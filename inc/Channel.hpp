/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:56:52 by sbouzidi          #+#    #+#             */
/*   Updated: 2022/05/22 15:56:55 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <map>
#include <vector>
#include "./User.hpp"
#include "./CommandList/CommandList.hpp"


class Channel {

    private:
            std::string _name;
            std::string _topic;
//            std::vector<User*> _members;

    public:
            Channel(std::string name, std::string topic);

};


#endif