<?php

namespace Tests\App\Models;

use Ice\Auth\Driver\Model\Roles as IceRoles;

class MongoRoles extends IceRoles
{
    protected $service = 'mongo';
    protected $from = 'roles';
}
