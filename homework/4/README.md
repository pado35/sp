有兩台ATM使用Thread，一台不斷存100元，一台不斷領100元
有使用mutex的版本會鎖住關鍵區域，避免race condition
未使用mutex的版本則會發生Race Condition