<?php
namespace MongoDB;

if (!class_exists(__NAMESPACE__ . '\Client')) {
    class Client {}
}

if (!class_exists(__NAMESPACE__ . '\BSON\ObjectID')) {
    class ObjectID {}
}

if (!class_exists(__NAMESPACE__ . '\BSON\Regex')) {
    class Regex {}
}

if (!class_exists(__NAMESPACE__ . '\BSON\UTCDateTime')) {
    class UTCDateTime {
        public function toDateTime() {}
    }
}
