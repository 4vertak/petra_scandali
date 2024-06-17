COMMENT ON TABLE person_discounts 
	IS 'Информация о персональных скидках';
COMMENT ON COLUMN person_discounts.id 
	IS 'Идентификатор строки';
COMMENT ON COLUMN person_discounts.person_id 
	IS 'Идентфикатор клиента из списка заказов';
COMMENT ON COLUMN person_discounts.pizzeria_id 
	IS 'Идентфикатор пиццерии откуда клиент сделал заказ';
COMMENT ON COLUMN person_discounts.discount 
	IS 'Персональная скидка клиента на каждой пиццерии. Размер зависит от количества заказов';