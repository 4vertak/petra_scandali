SELECT DISTINCT	
	COALESCE("user".name, 'not defined') AS name,
    COALESCE("user".lastname, 'not defined') AS lastname,
    balance.type,
    balance.money,
    COALESCE(currency.name, 'not defined') AS currency_name,
    COALESCE(FIRST_VALUE(currency.rate_to_usd) OVER(PARTITION BY currency.id order by currency.updated DESC), 1) AS last_rate_to_usd
FROM balance
LEFT JOIN "user" ON balance.user_id="user".id
LEFT JOIN currency ON balance.currency_id=currency.id
ORDER BY name DESC, lastname, type;