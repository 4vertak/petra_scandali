-- insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29'); 
-- insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

SELECT DISTINCT COALESCE(u.name, 'not defined') AS name,
       COALESCE(u.lastname, 'not defined') AS lastname,
       c.name AS currency_name,
       CAST (b.money * COALESCE(
   (SELECT rate_to_usd
   FROM currency
   WHERE b.currency_id = currency.id AND currency.updated < b.updated
   ORDER BY currency.updated DESC
   LIMIT 1),
   (SELECT rate_to_usd
   FROM currency
   WHERE b.currency_id = currency.id AND currency.updated > b.updated
   ORDER BY currency.updated ASC
   LIMIT 1)) AS FLOAT) AS currency_in_usd
FROM balance b
JOIN (SELECT DISTINCT id, name FROM currency) AS c ON c.id = b.currency_id
LEFT JOIN "user" u ON b.user_id = u.id
ORDER BY name DESC, lastname, currency_name;