from cs50 import get_float


def main():
    change = 0
    value = 0

    # get user input
    while True:
        change = get_float(" Change Owed: ")
        if change < 0:
            change = get_float(" Change Owed: ")
        else:
            break

    # change to cents
    change = change * 100

    # calculate how many quarters to give customer
    value = 25
    quar = calc_coins(change, value)
    change = change - (quar * value)

    # calculate how many dimes to give customer
    value = 10
    dim = calc_coins(change, value)
    change = change - (dim * value)

    # calculate how many nickles to give customers
    value = 5
    nick = calc_coins(change, value)
    change = change - (nick * value)

    # calculate how many pennies to give customers
    value = 1
    penn = calc_coins(change, value)

    # get the sum of coins
    total = quar + dim + nick + penn
    print(f"{total}")


def calc_coins(change, value):
    coin = 0
    while change >= value:
        coin += 1
        change = change - value
    return coin


main()
