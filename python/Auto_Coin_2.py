import pyupbit

# key
f = open("/home/DevStone/upbit.txt")
lines = f.readlines()
access = lines[0].strip()
secret = lines[1].strip()
f.close()
upbit = pyupbit.Upbit(access, secret)

# 매수
krw_balance = upbit.get_balance("KRW")#보유 현금 조회
upbit.buy_market_order("KRW-BTC", krw_balance * 0.9995)#시장가 매수 주문
upbit.buy_limit_order("KRW-BTC", 8000000, krw_balance * 0.9995)#지정가 매수 주문

# 매도
btc_balance = upbit.get_balance("KRW-BTC")#보유 코인 수 조회
upbit.sell_market_order("KRW-BTC", btc_balance)#시장가 매도 주문
upbit.sell_limit_order("KRW-BTC", 10000000, btc_balance)# 지정가 매도 주문
