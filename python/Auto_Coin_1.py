#pip install pyupbit
import pyupbit

#ApiKey 등록
f = open("/home/DevStone/upbit.txt")
lines = f.readlines()
access = lines[0].strip()
secret = lines[1].strip()
f.close()
upbit = pyupbit.Upbit(access, secret)


#상장 목록 조회
coin_list = pyupbit.get_tickers(fiat="ALL")
print(coin_list)


#종목 캔들 조회
df = pyupbit.get_ohlcv('KRW-BTC', "Day", count=200)
close = df['close']
high = df['high']

print(df) #<class 'pandas.core.frame.DataFrame'>
print(close) #종가
print(high) #고가
