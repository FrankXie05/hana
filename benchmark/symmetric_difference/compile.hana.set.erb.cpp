/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/integral_constant.hpp>
#include <boost/hana/set.hpp>
#include <boost/hana/symmetric_difference.hpp>
namespace hana = boost::hana;


int main() {
    <% half = input_size / 2 %>
    constexpr auto xs = hana::make_set(
        <%= (1..half).map { |n| "hana::int_<#{n}>" }.join(', ') %>
    );

    constexpr auto ys = hana::make_set(
        <%= (half..input_size).map { |n| "hana::int_<#{n}>" }.join(', ') %>
    );

    constexpr auto result = hana::symmetric_difference(xs, ys);
    (void)result;
}
