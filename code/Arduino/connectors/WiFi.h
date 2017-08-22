﻿#pragma once
#include "ConnectingDevice.h"

class WiFi : public ConnectingDevice
{
public:
	explicit WiFi(unsigned long speed);
	~WiFi();

	/**
	* @brief Убирает посланную команду в возвращаемом от модуля сообщении
	*/
	virtual bool ReturningCommandsOff();

	/**
	* @brief Проверка версии прошивки
	* @return Вся информация о версии прошивки модуля
	*/
	virtual String VersionCheck();

	/**
	* @brief Выводит список доступных модулю в данный момент сетей для подключения
	* @return Строка со списком всех доступных сетей
	*/
	virtual String NetsList();

	/**
	* @brief Получение текущих IP и MAC
	* @return Строка с текущими IP и MAC
	*/
	virtual String CheckIPandMAC();

	/**
	* @brief Изменяет рабочую скорость модуля
	* @param speed Скорость работы модуля
	*/
	virtual bool ChangeSpeed(unsigned long speed);

	/**
	* @brief Перезапускает модуль
	* @return Готовность модуля к работе
	*/
	virtual bool Reset();

	/**
	* @brief Перезапускает модуль
	* @param speed Скорость работы модуля
	* @return Готовность модуля к работе
	*/
	virtual bool Reset(unsigned long speed);

	/**
	* @brief Делает проверку на успешность посланной команды
	* @return Команда выполнена
	*/
	virtual bool CheckOnAnswer();

	/**
	* @brief Делает первичную проверку модуля
	* @return Готовность модуля к работе
	*/
	virtual bool CheckOnReady();

	/**
	* @brief Переводит модуль в режим клиента
	*/
	virtual bool Close();

	/**
	* @brief Переводит модуль в режим хоста без TCP
	*/
	virtual bool Open();

	/**
	* @brief Включает TCP
	* @param Принимает номер порта
	*/
	virtual bool UseTCP(int port);

	/**
	* @brief Устанавливает параметры хоста без записи в кэш
	* @param name имя точки доступа, password пароль и port номер порта для вызова функции UseTCP
	*/
	virtual bool CreateCurrentHost(String name, String password, int port);

	/**
	* @brief Устанавливает параметры хоста с записью в кэш
	* @param name имя точки доступа, password пароль и port номер порта для вызова функции UseTCP
	*/
	virtual bool CreateStaticHost(String name, String password, int port);

	/**
	* @brief Функция отправки, добавляющая "\r\n" ко всем командам без проверки статуса модуля
	*/
	virtual void StartingSend(String command);

	/**
	* @brief Функция отправки, добавляющая "\r\n" ко всем командам и проверяющая статус модуля
	*/
	virtual void Send(String command);

	/**
	* @brief Функция приёма ответа с модуля, добавляющая задержку перед получением ответа
	*/
	virtual String Scan();

	/**
	* @brief Преобразует возвращаемую строку
	* @return Отфильтрованный ответ
	*/
	virtual String ReturnInfo();

	/**
	* @brief Функция выхода при критической ошибке
	*/
	virtual void FatalError();

	/**
	* @brief Функция отправки данных пользователю
	*/
	virtual String Write(String message);

	/**
	* @brief Функция приёма данных от пользователя
	*/
	virtual String Read();

	/**
	* @brief Функция выхода при критической ошибке
	*/
	virtual String CheckStatus();

	/**
	* @brief Индикатор проведённой инициализации модуля
	*/
	bool isInited = false;

private:

	/**
	* @brief Индикатор готовности модуля к работе
	*/
	bool ready = false;

	/**
	* @brief Индикатор состояния модуля клиент/хост
	*/
	bool opened = false;
};