import { createRouter, createWebHistory } from 'vue-router'

import Dashboard from '../views/Dashboard.vue'
import Settings from '../views/Settings.vue'

const routes = [
  { path: '/', name: 'Dashboard', component: Dashboard },
  { path: '/settings', name: 'Settings', component: Settings },
]

export const router = createRouter({
  history: createWebHistory(),
  routes,
})
