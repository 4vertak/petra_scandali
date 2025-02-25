WITH balance_aggregated AS (
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
)

SELECT
	name,
    lastname,
    type,
    SUM(money) AS volume,
    currency_name,
    last_rate_to_usd,
    CAST(SUM(money) * last_rate_to_usd AS FLOAT) AS total_volume_in_usd
FROM balance_aggregated
GROUP BY name, lastname, type, currency_name, last_rate_to_usd
ORDER BY name DESC, lastname, type;