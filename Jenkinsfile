pipeline {
  agent {
    docker {
      image 'kitware/cmake:ci-hip5.5-x86_64-2023-06-01'
    }

  }
  stages {
    stage('Build') {
      steps {
        cmakeBuild(installation: 'InSearchPath', sourceDir: 'src', buildDir: 'build')
      }
    }

  }
}