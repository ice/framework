<?php

namespace Tests\App\Models;

use Ice\Auth\Driver\Model\Users as IceUsers;
use Ice\Validation;

class Users extends IceUsers
{
    protected $fields = [
        'id',
        'email',
        'username',
        'password',
        'logins',
        'lastlogin'
    ];

    public function initialize()
    {
        parent::initialize();

        $this
            ->hasMany('id', __NAMESPACE__ . '\Posts', 'user_id', ['alias' => 'Posts'])
            ->hasMany('id', __NAMESPACE__ . '\Comments', 'user_id', ['alias' => 'Comments']);
    }

    public function create($fields = [], Validation $extra = null)
    {
        $model = $this;

        $this->di->hook('model.before.create', function ($model) {
            $model->set('password', md5($model->get('password')));
            $model->set('logins', intval($model->get('logins')));
        }, $model);

        $create = parent::create($fields, $extra);

        $this->di->clearHooks('model.before.create', $model);

        return $create;
    }
}
