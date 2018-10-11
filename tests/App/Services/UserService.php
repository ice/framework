<?php

namespace Tests\App\Services;

use Ice\Mvc\Service;
use Tests\App\Models\Users;

class UserService extends Service
{
    public function __construct(Users $model)
    {
        $this->setModel($model);
    }
}
