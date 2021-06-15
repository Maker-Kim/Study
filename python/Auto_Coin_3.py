import jwt
import uuid
import requests
import pyupbit

f = open("/home/DevStone/upbit.txt")
lines = f.readlines()
access = lines[0].strip()
secret = lines[1].strip()
f.close()
upbit = pyupbit.Upbit(access, secret)


server_url = "https://api.upbit.com"
payload = {
    'access': access,
    'nonce': str(uuid.uuid4()),
}

jwt_token = jwt.encode(payload, secret)
authorize_token = 'Bearer {}'.format(jwt_token)
headers = {"Authorization": authorize_token}
print(authorize_token)

res = requests.get(server_url + "/v1/accounts", headers=headers)
print(res.json())


#주문조회
ret = upbit.get_order('KRW-BTC')
print(ret)


#주문취소
uuid = '00000000-0000-0000-0000-000000000000'
upbit.cancel_order(uuid)


