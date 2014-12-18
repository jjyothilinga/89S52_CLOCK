void App_init(void);
void App_task(void);

typedef enum
{
	IDLE, NEW_TOKEN, CALL
}APP_STATE;


typedef struct _APP
{
	APP_STATE state;
	APP_STATE key;

}APP;

	